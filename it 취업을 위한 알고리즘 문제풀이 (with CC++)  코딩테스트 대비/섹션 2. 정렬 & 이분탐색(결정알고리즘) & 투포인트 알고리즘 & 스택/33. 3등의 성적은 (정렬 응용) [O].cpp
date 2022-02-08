#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>	// cin,cout말고 이제 c에서 제공하는 sanf, printf 사용 - 속도가 조금 더 빠름
#include<vector>
#include<algorithm>

using namespace std;

int main()
{
	//freopen("input.txt", "rt", stdin); // input.txt 파일 읽기
	int a[101];
	int n, i, j, idx, tmp, count = 0;
	scanf("%d", &n);

	for (i = 0; i < n; i++)
		scanf("%d", &a[i]);

	for (i = 0; i < n - 1; i++)	// 점수들을 선택정렬로 내림차순 정렬
	{
		idx = i;
		for (j = i + 1; j < n; j++)
		{
			if (a[j] > a[idx])
				idx = j;
		}
		tmp = a[i];
		a[i] = a[idx];
		a[idx] = tmp;
	}

	for (i = 1; i < n; i++)
	{
		if (a[i - 1] != a[i]) // 이어지는 점수가 같으면 같은 등수니까 넘어가고 다를때만 등수 증가하고 그때 점수 저장
		{
			count++;
		}

		if (count == 2)	// 2번 틀렸다는건 3등 점수가 나왔다는 거니까 3등 점수 출력
		{
			printf("%d", a[i]);
			break;
		}
	}

	return 0;
}
