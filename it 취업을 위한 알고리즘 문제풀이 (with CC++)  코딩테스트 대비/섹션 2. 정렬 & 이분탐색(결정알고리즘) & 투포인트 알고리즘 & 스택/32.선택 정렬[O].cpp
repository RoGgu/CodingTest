#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>	// cin,cout말고 이제 c에서 제공하는 sanf, printf 사용 - 속도가 조금 더 빠름
#include<vector>
#include<algorithm>

using namespace std;

int main()
{
	//freopen("input.txt", "rt", stdin); // input.txt 파일 읽기
	// 선택 정렬
	// 이중 for문으로 돌면서 첫번째 for문 뒤에 수부터 다시 for문 돌면서 가장 작은수를 찾아서 바꾸는 형식

	int a[100];
	int n, i, j, idx, tmp;
	scanf("%d", &n);

	for (i = 0; i < n; i++)
	{
		scanf("%d", &a[i]);
	}

	for (i = 0; i < n - 1; i++)
	{
		idx = i;
		for (j = i + 1; j < n; j++)
		{
			if (a[j] < a[idx]) // 현재 인덱스의 수랑 비교해서 더 작으면 더 작은수 인덱스 저장
				idx = j;	// 가장 작은수가 있는 인덱스 위치를 넣어줌
		}
		tmp = a[i];	// 작은값으로 있는 인덱스에 값이랑 i 값이랑 바꾼다
		a[i] = a[idx];
		a[idx] = tmp;
	}

	for (i = 0; i < n; i++)
	{
		printf("%d", a[i]);
	}

	return 0;
}
