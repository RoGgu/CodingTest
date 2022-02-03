#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>	// cin,cout말고 이제 c에서 제공하는 sanf, printf 사용 - 속도가 조금 더 빠름
#include<vector>
#include<algorithm>

using namespace std;
int main()
{
	//freopen("input.txt", "rt", stdin); // input.txt 파일 읽기
	int i, j, n, temp, num2 = 0, num5 = 0, cnt = 0;; // i: for문 카운트, j : 소인수 나누기, n : 입력 수, temp : 소인수로 나눈 후 값, num2: 소인수 2의 개수, num5: 소인수 5의 개수, cnt :총 0의 개수
	scanf("%d", &n);

	for (i = 2; i <= n; i++)
	{
		temp = i;
		j = 2;
		while (true)
		{
			if (temp % j == 0)	// 2부터 나누면서 소인수 개수 체크
			{
				temp = temp / j;
				if (j == 2)	// 소인수 2와 5의 갯수 카운트
					num2++;
				else if (j == 5)
					num5++;
			}
			else
				j++;

			if (temp == 1) // 1이면 이미 다나눠진거라서 다음수로 넘어감
				break;
		}
	}


	if (num2 <= num5)	// 짝이 맞아야해서 둘 중 낮은 갯수로 출력
		cnt = num2;
	else
		cnt = num5;

	printf("%d", cnt);
	return 0;
}
