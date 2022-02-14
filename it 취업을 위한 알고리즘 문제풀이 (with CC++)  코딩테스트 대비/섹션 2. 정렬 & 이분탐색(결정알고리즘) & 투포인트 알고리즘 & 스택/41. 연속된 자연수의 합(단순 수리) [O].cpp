#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>	// cin,cout말고 이제 c에서 제공하는 sanf, printf 사용 - 속도가 조금 더 빠름
#include<vector>
#include<algorithm>

using namespace std;

int main()
{
	//freopen("input.txt", "rt", stdin); // input.txt 파일 읽기
	int n, i, num, tmp, cnt = 0;
	// n: 입력 받은 수, i: 만약 갯수에 맞게 떨어질떄 for문 카운트, num : 연속된 수의 개 수 , tmp : 연속된 수 뺸만큼의 남은 수, cnt : 총 나열된 자연수로 나온 수식 개수
	scanf("%d", &n);


	tmp = n;
	num = 1; // 일단 1을 뺴준다 최소 2개 자리수니까
	tmp--;
	while (tmp > 0) // 구하는 공식 총 더하는 개수 를 원래 수에서 뺴고 남은 수를 개 수로 나눠서 나머지가 없으면 나열된 수로 표시되는 수
	{
		num++;
		tmp -= num; // 나열되는 수만큼 뺸다

		if (tmp % num == 0)	// 나열되는 수의 개수의 나머지가 0이면  개수를 몫으로 나누고 1부터 더 해지면 나열되는 수들
		{
			for (i = 1; i < num; i++)
			{
				printf("%d + ", tmp / num + i);
			}
			printf("%d = %d\n", (tmp / num + i), n);
			cnt++;
		}
	}

	printf("%d", cnt); // 개수 출력

	return 0;
}
