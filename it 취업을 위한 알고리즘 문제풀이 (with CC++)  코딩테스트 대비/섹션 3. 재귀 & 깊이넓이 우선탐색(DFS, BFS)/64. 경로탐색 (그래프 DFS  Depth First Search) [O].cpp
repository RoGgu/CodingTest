#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>	// cin,cout말고 이제 c에서 제공하는 sanf, printf 사용 - 속도가 조금 더 빠름
#include<vector>
#include<algorithm>

using namespace std;

int n, m;
int map[21][21] = { 0 };
int ch[30] = { 0 };
int result = 0;



void DFS(int v)
{
	if (v == n) // 도착지에 도착했는지 체크
	{
		// 경로 출력하는 코드
		//for (int i = 0; i < 30; i++)
		//{
		//	if (ch[i] == 1)
		//		printf("%d ", i);
		//}
		//printf("\n");

		result++;
		return;
	}
	else
	{
		for (int i = 1; i <= n; i++) // 갈 수있는 정점 찾을려고 for문 돔
		{
			if (ch[i] != 1 && map[v][i] == 1) // 이미 간 경로는 패스, 연결되있는지 확인
			{
				ch[i] = 1; // 이제 간 겨올니까 체크함
				DFS(i);
				ch[i] = 0; // 갔다가 나온거니까 체크 풀어줌
			}
		}
	}
}

int main()
{
	freopen("input.txt", "rt", stdin); // input.txt 파일 읽기
	int i, s, d;
	scanf("%d %d", &n, &m);

	for (i = 0; i < m; i++)
	{
		scanf("%d %d", &s, &d);
		map[s][d] = 1;
	}

	ch[1] = 1; //1부터 시작하니까 경로에 1 넣어줌
	DFS(1);

	printf("%d", result);
	return 0;
}
