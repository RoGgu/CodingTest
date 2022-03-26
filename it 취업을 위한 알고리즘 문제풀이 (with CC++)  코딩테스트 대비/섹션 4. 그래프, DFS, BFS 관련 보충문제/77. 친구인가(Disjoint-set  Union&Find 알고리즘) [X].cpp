#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>	// cin,cout말고 이제 c에서 제공하는 sanf, printf 사용 - 속도가 조금 더 빠름
#include<vector>
#include<queue>
#include<algorithm>

using namespace std;

// 다시 풀기 !!!!!!!!!!!!!!!!!!!

int unf[1001];

int Find(int v)
{
	if (v == unf[v])
		return v;
	else
		unf[v] = Find(unf[v]);
}

void Union(int a, int b)
{
	a = Find(a);
	b = Find(b);
	if (a != b)
		unf[a] = b;
}


int main()
{
	//freopen("input.txt", "rt", stdin); // input.txt 파일 읽기
	int n, m, i, j, a, b;
	bool res = false;
	scanf("%d %d", &n, &m);

	for (i = 1; i <= n; i++)
		unf[i] = i;

	for (i = 1; i <= m; i++)
	{
		scanf("%d %d", &a, &b);
		Union(a, b);
	}

	scanf("%d %d", &a, &b);
	a = Find(a);
	b = Find(b);

	if (a == b)
		printf("YES");
	else
		printf("NO");

	return 0;
}
