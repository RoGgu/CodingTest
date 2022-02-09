#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>	// cin,cout말고 이제 c에서 제공하는 sanf, printf 사용 - 속도가 조금 더 빠름
#include<vector>
#include<algorithm>

using namespace std;

int main()
{
	//freopen("input.txt", "rt", stdin); // input.txt 파일 읽기
	int a[101];
	int n, i, j, tmp;
	scanf("%d", &n);

	for (i = 0; i < n; i++)
		scanf("%d", &a[i]);

	for (i = 0; i < n - 1; i++)
	{
		for (j = 0; j < n - i - 1; j++) // 한번 돌떄마다 마지막 수들은 정렬된 수로 하나씩 차니까 그 전까지만 돔
		{
			if (a[j] > 0 && a[j + 1] < 0) // 양수이고 다음수 가음수이면 양수를 뒤로 밀어줌
			{
				tmp = a[j];
				a[j] = a[j + 1];
				a[j + 1] = tmp;
			}
		}
	}

	for (i = 0; i < n; i++)
		printf("%d ", a[i]);

	return 0;
}
