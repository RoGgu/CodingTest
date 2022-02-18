#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>	// cin,cout말고 이제 c에서 제공하는 sanf, printf 사용 - 속도가 조금 더 빠름
#include<vector>
#include<algorithm>

using namespace std;

int main()
{
	//freopen("input.txt", "rt", stdin); // input.txt 파일 읽기
	int n, k, i, cnt = 0, pos = 0, kCount = 1;
	scanf("%d %d", &n, &k);
	vector<int> a(n);

	while (cnt < n - 1) // 마지막 왕자 남을때까지 반복
	{
		if (a[pos] != 1 && kCount == k)	// 이미제 제외도니 왕자 무시 && k 카운터랑 맞으면 그때 제거
		{
			a[pos] = 1;
			kCount = 1;
			cnt++;	// 제외된 왕자 수 카운트
		}
		else
		{
			if (a[pos] != 1)	// 만약 제외되지 않은 왕자면 kCount증가
				kCount++;
		}

		pos++;
		if (pos >= n) // 인덱스 범위 넘어가면 초기화
			pos = 0;
	}

	for (i = 0; i < n; i++)	// 이제 제외되지 않은 왕자 출력
	{
		if (a[i] == 0)
			printf("%d", i + 1);
	}

	return 0;
}
