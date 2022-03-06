#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>	// cin,cout말고 이제 c에서 제공하는 sanf, printf 사용 - 속도가 조금 더 빠름
#include<vector>
#include<algorithm>

using namespace std;

int n, total = 0;
int a[11];
bool found;

void DFS(int L, int sum)
{
	if (sum > total / 2 || found == true) // 이미 총합의 반 지났으면 false, 이미 찾았으면 나머지 체크 X
		return;

	if (L >= n)
	{
		if (sum == (total - sum)) // 현재 집합 더한게 총합의 절반이면 나머지도 절반이니까 true
		{
			found = true;
		}
		return;
	}
	else
	{
		DFS(L + 1, sum + a[L]); // 왼쪽은 현재 index값 더 한거 넘겨주고
		DFS(L + 1, sum); // 오른쪽은 안 더하고 넘겨줌
	}

}

int main()
{
	//freopen("input.txt", "rt", stdin); // input.txt 파일 읽기
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
	{
		scanf("%d", &a[i]);
		total += a[i];
	}

	DFS(0, 0);

	if (found == true)
		printf("YES");
	else
		printf("NO");


	return 0;
}
