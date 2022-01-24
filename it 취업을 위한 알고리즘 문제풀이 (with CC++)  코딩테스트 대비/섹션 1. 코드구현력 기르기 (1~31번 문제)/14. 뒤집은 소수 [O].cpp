#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>	// cin,cout말고 이제 c에서 제공하는 sanf, printf 사용 - 속도가 조금 더 빠름

int reverse(int x)
{
	int result = 0;

	while (x > 0) // ex)3700 같이 뒤집으면 0037인데 앞에 00은 무시해줘야함
	{
		result = (result * 10) + (x % 10);
		x = x / 10;
	}

	return result;
}

bool isPrime(int x)
{
	int i;
	bool result = true;

	for (i = 2; i < x; i++)
	{
		if (x % i == 0)
		{
			result = false;
			break;
		}
	}
	return result;
}

int main() {
	//freopen("input.txt", "rt", stdin); // input.txt 파일 읽기
	int n, num, reverseNum, i;
	scanf("%d", &n);

	for (i = 0; i < n; i++)
	{
		scanf("%d", &num);
		reverseNum = reverse(num);	// 수를 뒤집는다

		if (reverseNum == 1)	// 뒤집은 수가 1이면 1은 소수아니니까 넘긴다
			continue;

		if (isPrime(reverseNum) == true)// 소수인지 체크
			printf("%d ", reverseNum);
	}

	return 0;
}
