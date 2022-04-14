#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>	// cin,cout말고 이제 c에서 제공하는 sanf, printf 사용 - 속도가 조금 더 빠름
#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
#include<cstdlib>

using namespace std;


int main()
{
	//freopen("input.txt", "rt", stdin); // input.txt 파일 읽기
	int n, tmp, cnt = 0;
	int dy[8] = { 1, 1, 0, -1, -1, -1,  0,  1 }; // 8방향 회전
	int dx[8] = { 0, 1, 1,  1,  0, -1, -1, -1 };
	cin >> n;
	vector<vector<int>> map(n, vector<int>(n));
	vector<vector<int>> chMap(n, vector<int>(n));
	queue<pair<int, int>> q;

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cin >> tmp;
			map[i].push_back(tmp);
			chMap[i].push_back(0);
		}
	}

	for (int y = 0; y < n; y++)
	{
		for (int x = 0; x < n; x++)
		{
			if (map[y][x] == 1 && chMap[y][x] == 0) // 현재 땅이 있고 체크안된 경우에만 섬 연결 시작
			{
				cnt++; // 새로운 섬이니까 카운터 증가
				q.push(make_pair(y, x));
				while (q.empty() == false) // 현재 땅이랑 연결된 곳은 전부 같은 성이라쳐서 체크해버림
				{
					int currentY = q.front().first;
					int currentX = q.front().second;
					q.pop();
					chMap[currentY][currentX] = 1;

					for (int i = 0; i < 8; i++) // 대각선 이동도 가능하니까 8방향으로 체크
					{
						int nextY = currentY + dy[i];
						int nextX = currentX + dx[i];
						if (nextY >= 0 && nextY < n && nextX >= 0 && nextX < n)
						{
							if (map[nextY][nextX] == 1 && chMap[nextY][nextX] == 0)
								q.push(make_pair(nextY, nextX));
						}
					}
				}
			}
		}
	}

	cout << cnt << endl;

	return 0;
}
