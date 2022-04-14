#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>	// cin,cout말고 이제 c에서 제공하는 sanf, printf 사용 - 속도가 조금 더 빠름
#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
#include<cstdlib>

using namespace std;

// 미로 최단거리 탐색은 BFS로 찾는다

int main()
{
	freopen("input.txt", "rt", stdin); // input.txt 파일 읽기
	int n = 7, tmp, cnt = 0;
	int dy[4] = { -1, 1,  0, 0, }; // 4방향 회전 상하좌우
	int dx[4] = { 0, 0, -1, 1, };
	vector<vector<int>> map(n, vector<int>(n));
	vector<vector<int>> dis(n, vector<int>(n)); // 각 위치에 도달하는데 소요된 거리 세팅
	queue<pair<int, int>> q;

	for (int y = 0; y < n; y++)
	{
		for (int x = 0; x < n; x++)
		{
			cin >> tmp;;
			map[y][x] = tmp;
		}
	}

	q.push(make_pair(0, 0));
	dis[0][0] = 0;

	while (q.empty() == false)
	{
		int y = q.front().first;
		int x = q.front().second;
		q.pop();

		for (int i = 0; i < 4; i++)
		{
			int nextY = y + dy[i];
			int nextX = x + dx[i];

			if (nextY < 0 || nextY >= n || nextX < 0 || nextX >= n)
				continue;

			if (map[nextY][nextX] == 0 && dis[nextY][nextX] == 0)
			{
				dis[nextY][nextX] = dis[y][x] + 1; // next 위치를 발견한 발견한 위치까지에 소요된 거리 +1

				q.push(make_pair(nextY, nextX));
			}
		}
	}

	if (dis[6][6] == 0) // 거리가 0 이면 도달 못한거니까 -1 표시
		cout << -1 << endl;
	else
		cout << dis[6][6] << endl;

	return 0;
}
