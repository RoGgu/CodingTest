#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>	// cin,cout말고 이제 c에서 제공하는 sanf, printf 사용 - 속도가 조금 더 빠름
using namespace std;

int digit_sum(int x) // 자릿수의 합을 리턴하는 함수
{
	int sum = 0;

	while (x > 0) // 첫번째 자릿수부터 더하면서 10씩 나눠줌
	{
		sum += x % 10;
		x = x / 10;
	}

	return sum;
}

int main() {
	//freopen("input.txt", "rt", stdin); // input.txt 파일 읽기
	int n, num, i, sum, res, max = -2147000000;
	// 총 수, for문 돌때 입력받은 수, for문 카운터, 현재 num의 자릿수의 합, 현재 자릿수의 합이 가장 큰 수, 가장 큰 자릿수의 합
	scanf("%d", &n);

	for (i = 0; i < n; i++)
	{
		scanf("%d", &num);
		sum = digit_sum(num); // 자릿수의 합 받아옴
		if (sum > max)	// 자릿수의 합이 더 크면 바로 바꿈
		{
			max = sum;
			res = num;
		}
		else if (sum == max)	// 같을 경우 기존 수랑 크기비교해서 크면 바꿈
		{
			if (num > res)
			{
				res = num;
			}
		}
	}

	printf("%d", res);
	return 0;
}
