#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>	// cin,cout말고 이제 c에서 제공하는 sanf, printf 사용 - 속도가 조금 더 빠름
#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
#include<cstdlib>

using namespace std;

int map[21][21], ch[21][21];
int dx[4] = { -1, 0, 1, 0 };
int dy[4] = { 0, 1, 0, -1 };

struct State // 심바로부터 해당 좌표 해당 값
{
	int x, y, dis;
	State(int a, int b, int c)
	{
		x = a;
		y = b;
		dis = c;
	}

	bool operator<(const State& other) const
	{
		if (dis == other.dis) // 거리 같으면 위아래 나타내느 X 좌표 우선으로
		{
			if (x == other.x) // 높이가 같으면 좌우 기준으로
				return y > other.y;
			else
				return x > other.x;
		}
		else
			return dis > other.dis; // 최소 힙 만들어지도록 리턴
	}
};

struct Lion // 심바의 상태
{
	int x, y, s, ate;
	void sizeUp()
	{
		ate = 0;
		s++;
	}
};

int main()
{
	//freopen("input.txt", "rt", stdin); // input.txt 파일 읽기
	int n, i, j, res = 0;
	priority_queue<State> Q;
	Lion simba;

	scanf("%d", &n);
	for (i = 1; i <= n; i++)
	{
		for (j = 1; j <= n; j++)
		{
			scanf("%d", &map[i][j]);
			if (map[i][j] == 9)
			{
				simba.x = i; // 심좌 현재 위치 표시
				simba.y = j;
				map[i][j] = 0; // 심바 바로 이동시킬 꺼라서 현재 심바위치 0으로 표시
			}

		}
	}
	Q.push(State(simba.x, simba.y, 0));
	simba.s = 2; // 심바 처음 사이즈는 2
	simba.ate = 0; // 현재 먹은애 없어서 0

	while (!Q.empty())
	{
		State tmp = Q.top();
		Q.pop();
		int x = tmp.x;
		int y = tmp.y;
		int z = tmp.dis; // dis 는 심바가 그 곳까지 갔을때 최초부터 소요된 총 거리다 

		if (map[x][y] != 0 && map[x][y] < simba.s) // 먹을 수 있는 토끼일 경우
		{
			simba.x = x;
			simba.y = y;
			simba.ate++;
			if (simba.ate >= simba.s)
				simba.sizeUp();

			map[x][y] = 0; // 토끼 먹어서 있던 자리 0으로 만듬
			for (i = 1; i <= n; i++) // 먹기전에 체크헀던거 다 초기화
			{
				for (j = 1; j <= n; j++)
					ch[i][j] = 0;
			}
			while (!Q.empty()) // 먹기전에 미리 찾아둔 애들 다 지움
				Q.pop();
			res = tmp.dis; // 총 거리 값 세팅
		}

		for (i = 0; i < 4; i++)
		{
			int xx = x + dx[i];
			int yy = y + dy[i];

			if (xx < 1 || xx >n || yy <1 || yy >n || // 범위 벗어나거나
				map[xx][yy] > simba.s || ch[xx][yy] > 0) // 토끼가 사이즈 더 큰경우나 이미 체크한경우 패스
				continue;

			Q.push(State(xx, yy, z + 1)); // 최초부터 현재 위치까지 온 거리값 + 1
			ch[xx][yy] = 1;
		}
	}

	printf("%d\n", res);

	return 0;
}
