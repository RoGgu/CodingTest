#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>	// cin,cout말고 이제 c에서 제공하는 sanf, printf 사용 - 속도가 조금 더 빠름
#include<vector>
#include<algorithm>

using namespace std;


int n, m, i, cnt;

int a[11];

void DFS(int L, int sum)
{
	if (L >= n)
	{
		if (sum == m) // 특정 수랑 같아지면 카운트 증가
			cnt++;
		return;
	}
	else
	{
		// 세가지 경우로 나눈다 
		// 더하는 경우, 아예 포함 안시키는 경우, 뺴는경우
		DFS(L + 1, sum + a[L]);
		DFS(L + 1, sum);
		DFS(L + 1, sum - a[L]);
	}
}

int main()
{
	//freopen("input.txt", "rt", stdin); // input.txt 파일 읽기
	scanf("%d %d", &n, &m);

	for (i = 0; i < n; i++)
		scanf("%d", &a[i]);

	DFS(0, 0);

	if (cnt == 0) // 카운트 0으로 찾는수가 없을 경우 -1 출력
		printf("-1");
	else
		printf("%d", cnt);

	return 0;
}
