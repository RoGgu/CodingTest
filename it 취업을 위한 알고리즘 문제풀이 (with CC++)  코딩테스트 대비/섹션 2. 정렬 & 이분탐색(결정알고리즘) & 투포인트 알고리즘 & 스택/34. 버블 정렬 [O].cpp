#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>	// cin,cout말고 이제 c에서 제공하는 sanf, printf 사용 - 속도가 조금 더 빠름
#include<vector>
#include<algorithm>

using namespace std;

// 버블정렬 
// 배열을 돌면서 바로 이웃한 앞 뒤 숫자를 비교해서 정렬함
// 오름차순 정렬 시 맨뒤에 큰수가 하나씩 정렬되면서 쌓임
// 이중 for문으로 i는 n-1까지 돌고 j는 마지막엔 정렬된 수 들이 차니까 n-i-1까지만 돔 

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
			if (a[j] > a[j + 1]) // 바로 이웃한 수 비교해서 조건에 맞으면 바꿔줌
			{
				tmp = a[j];
				a[j] = a[j + 1];
				a[j + 1] = tmp;
			}
		}
	}

	for (i = 0; i < n; i++)
	{
		printf("%d ", a[i]);
	}

	return 0;
}
