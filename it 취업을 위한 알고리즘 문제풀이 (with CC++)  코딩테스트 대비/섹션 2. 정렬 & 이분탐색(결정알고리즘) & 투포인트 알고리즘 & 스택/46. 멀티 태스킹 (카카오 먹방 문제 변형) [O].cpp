#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>	// cin,cout말고 이제 c에서 제공하는 sanf, printf 사용 - 속도가 조금 더 빠름
#include<vector>
#include<algorithm>

using namespace std;

int main()
{
	//freopen("input.txt", "rt", stdin); // input.txt 파일 읽기
	int n, k, i, second = 0, pos = 0, cnt = 0, total = 0;
	scanf("%d", &n);
	vector<int> a(n);
	for (i = 0; i < n; i++)
	{
		scanf("%d", &a[i]);
		total += a[i];
	}
	scanf("%d", &k);

	if (total <= k) // 전체 작업 시간보다 정전되는 시간이 클경우 작업할꺼 없으니까 -1
	{
		printf("-1");
		return 0;
	}

	while (true)
	{
		if (second == k)	// 현재 작업해야 하는데 정전되면 정전 후 현재작업 해야될것이 답이다
		{
			printf("%d", pos + 1);
			break;
		}

		a[pos]--; // 현재 작업 시간감소
		pos++;	// 다음 작업 위치 찾아놓기
		if (pos == n)
			pos = 0;
		while (a[pos] == 0)	// 다음 작업해야할것을 찾는다 (작업시간 남아있는거)
		{
			pos++;
			if (pos == n)
				pos = 0;
		}
		second++; // 작업완료 후 시간증가
	}

	return 0;
}
