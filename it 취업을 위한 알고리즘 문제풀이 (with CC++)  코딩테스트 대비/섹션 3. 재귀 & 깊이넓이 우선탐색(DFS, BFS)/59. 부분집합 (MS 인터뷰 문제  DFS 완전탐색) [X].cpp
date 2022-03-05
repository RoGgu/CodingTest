#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>	// cin,cout말고 이제 c에서 제공하는 sanf, printf 사용 - 속도가 조금 더 빠름
#include<vector>
#include<algorithm>

using namespace std;

int n;
int ch[11];
void DFS(int L)
{
	int i;
	if (L == n + 1)
	{
		for (i = 1; i <= n; i++)
		{
			if (ch[i] == 1)
				printf("%d ", i);
		}
		puts(""); 		//printf("\n"); 줄바꿈 키워드

	}
	else
	{
		ch[L] = 1; // 왼쪽으로 갈때는 1로 켜줌
		DFS(L + 1);
		ch[L] = 0; // 오른쪽은 0으로 꺼줌
		DFS(L + 1);
	}
}

int main()
{
	//freopen("input.txt", "rt", stdin); // input.txt 파일 읽기
	scanf("%d", &n);
	DFS(1);

	return 0;
}
