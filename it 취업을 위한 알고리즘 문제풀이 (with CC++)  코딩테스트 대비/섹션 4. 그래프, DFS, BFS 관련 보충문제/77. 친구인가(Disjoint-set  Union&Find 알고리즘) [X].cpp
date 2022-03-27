#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>	// cin,cout말고 이제 c에서 제공하는 sanf, printf 사용 - 속도가 조금 더 빠름
#include<vector>
#include<queue>
#include<algorithm>

using namespace std;

int unf[1001];

int Find(int v)
{
	if (v == unf[v]) // 자기 배열의 수가 나올때까지 찾는다
		return v;
	else
		return unf[v] = Find(unf[v]); // 다시 반복으로 구할 필요 없도록 세팅다시 해준다.
}

void Unf(int a, int b)
{
	a = Find(a);
	b = Find(b);

	if (a != b) // 만약 현재 다른 그룹에 있다면 a에 b의 값을 넣어서 그룹을 연결해준다.
		unf[a] = b;
}

int main()
{
	//freopen("input.txt", "rt", stdin); // input.txt 파일 읽기
	int n, m, i, a, b;
	scanf("%d %d", &n, &m);
	for (i = 1; i <= n; i++) // 자기 배열의 수 넣어줌
		unf[i] = i;

	for (i = 1; i <= m; i++) // 숫자 쌍 돌면서 연결 세팅
	{
		scanf("%d %d", &a, &b);
		Unf(a, b);
	}

	scanf("%d %d", &a, &b);
	a = Find(a); 
	b = Find(b);

	if (a == b) // 두 수가 연결되어 같은 수가 나온다.
		printf("YES");
	else
		printf("NO");
	return 0;
}
