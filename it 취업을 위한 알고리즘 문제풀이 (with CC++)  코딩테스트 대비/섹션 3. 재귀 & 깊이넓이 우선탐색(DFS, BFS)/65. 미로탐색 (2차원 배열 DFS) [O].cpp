#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>	// cin,cout말고 이제 c에서 제공하는 sanf, printf 사용 - 속도가 조금 더 빠름
#include<vector>
#include<algorithm>

using namespace std;

const int n = 7; // 맵 크기는 7로 고정
int map[n][n] = { 0 }; // 맵
int checkMap[n][n] = { 0 }; // 경로 체크 배열
int cnt = 0; // 총 경로 수

int dx[] = { 1, -1,  0 , 0 }; // 상화좌우 방향 배열
int dy[] = { 0, 0, 1,  -1 };

void DFS(int y, int x)
{
	if (x == n - 1 && y == n - 1) // 마지막 배열 도착지에 도착했으면 카운트
	{
		cnt++;
		return;
	}
	else
	{
		for (int i = 0; i < 4; i++)
		{
			int moveX = x + dx[i];
			int moveY = y + dy[i];
			if (moveX < n && moveY < n && moveX >= 0 && moveY >= 0) // 배열범위 벗어나면 패스
				continue;
			
			if (map[moveY][moveX] == 0 && checkMap[moveY][moveX] == 0) // 갈 수 있는곳인지 체크, 이미 간곳인지 체크
			{
				checkMap[moveY][moveX] = 1; // 갔다고 기록
				DFS(moveY, moveX);
				checkMap[moveY][moveX] = 0; // 갔다 왔으니까 해제
			}
		}
	}
}

int main()
{
	//freopen("input.txt", "rt", stdin); // input.txt 파일 읽기
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
			scanf("%d", &map[i][j]);
	}

	checkMap[0][0] = 1;
	DFS(0, 0);

	printf("%d", cnt);
	return 0;
}
