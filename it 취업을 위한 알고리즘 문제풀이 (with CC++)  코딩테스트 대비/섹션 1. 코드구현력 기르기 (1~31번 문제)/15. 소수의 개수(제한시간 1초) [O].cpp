#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>	// cin,cout말고 이제 c에서 제공하는 sanf, printf 사용 - 속도가 조금 더 빠름

int main() {
	//freopen("input.txt", "rt", stdin); // input.txt 파일 읽기
	int n, i, j, flag, cnt = 0; // n : 입력 값, i j :for문 카운터, flag : 1이면 소수, cnt : 약수 갯 수 
	scanf("%d", &n);

	for (i = 2; i <= n; i++)
	{
		flag = 1;
		for (j = 2; j * j <= i; j++)	// 소수 체크는 그 수의 제곱근까지만 돌아도 알 수 있다.
		{
			if (i % j == 0)
			{
				flag = 0;
				break;
			}
		}

		if (flag == 1)
			cnt++;
	}

	printf("%d", cnt);
}
