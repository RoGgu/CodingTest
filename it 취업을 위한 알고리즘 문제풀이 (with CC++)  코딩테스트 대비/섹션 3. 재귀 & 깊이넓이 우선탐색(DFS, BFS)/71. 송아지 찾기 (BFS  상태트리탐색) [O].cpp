#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>	// cin,cout말고 이제 c에서 제공하는 sanf, printf 사용 - 속도가 조금 더 빠름
#include<vector>
#include<queue>
#include<algorithm>

using namespace std;


// 최단 거리 구하는건 넓이탐색트리 사용

int main()
{
	//freopen("input.txt", "rt", stdin); // input.txt 파일 읽기
	int s, e, i, pos, tmp;

	int move[] = { 1,-1,5 }; // 이동 방법 3가지 저장
	int dis[10001] = { 0 }; // 그 idx지점에 가는데 이동 횟수기록
	queue<int> q;
	scanf("%d %d", &s, &e);

	pos = s; // 자기 시작지점부터 시적
	q.push(pos);
	dis[pos] = 0;

	// 시작지점이 탑으로 되어서 그다음 1, -1, 5 더해서 갈 수 있는것들이 3개의 노드가 되는 개념
	while (!q.empty())
	{
		tmp = q.front();
		q.pop();

		if (tmp == e) // 노드가 도착지점이 나오면 끝난다
			break;

		for (i = 0; i < 3; i++)
		{
			pos = tmp + move[i];

			if (pos <= 0 || pos > 10000) // 음수거나 제한된 수 보다 크면 넘김
				continue;

			if (dis[pos] == 0) // 이미 그 이전 최소거리로 갔는지 체크
			{
				q.push(pos);

				dis[pos] = dis[tmp] + 1; // 자기 다음 도착 지점이니 거리 + 1
			}
		}
	}

	printf("%d", dis[e]);
	return 0;
}
