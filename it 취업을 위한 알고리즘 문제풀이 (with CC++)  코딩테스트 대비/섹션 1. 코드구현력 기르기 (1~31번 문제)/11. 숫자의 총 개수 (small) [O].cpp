#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>	// cin,cout말고 이제 c에서 제공하는 sanf, printf 사용 - 속도가 조금 더 빠름

using namespace std;
int main() {
	//freopen("input.txt", "rt", stdin); // input.txt 파일 읽기
	int num, temp, i, res = 0;	// num : 입력 수, temp : 자릿수 계산할때 나누고 남은 수, i : for 문 카운트, res : 자릿수의 총 합
	scanf("%d", &num);

	for (i = 1; i <= num; i++)	// 해당 자릿 수 * 자릿수의 총 갯수 를 1의자리부터 10의자리 100의자리 반복해서 더해줌
	{
		temp = i;
		while (temp > 0)
		{
			res++;
			temp = temp / 10;
		}
	}

	printf("%d", res);

	return 0;
}
