#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>	// cin,cout말고 이제 c에서 제공하는 sanf, printf 사용 - 속도가 조금 더 빠름

using namespace std;
int main() {
	freopen("input.txt", "rt", stdin); // input.txt 파일 읽기
	char a[50]; // 입력 값
	int i, cnt = 0, res = 0; // i : for문 카운트, cnt : 약수 갯 수, res : 숫자 만 출력
	scanf("%s", &a);

	for (i = 0; a[i] != '\0'; i++)
	{
		if (a[i] >= 48 && a[i] <= 57)	// 아스키 코드 값으로 0~9까지 찾아서 넣음
		{
			res = res * 10 + (a[i] - 48);	// 자릿 수 늘려주면서 수 더 해줌 (초반에 0들어오면 그대로라 첫 번쨰 0필터링)
		}
	}

	printf("%d\n", res);	// 숫자만 출력
	for (i = 1; i <= res; i++)	// 약수 갯 수구하기
	{
		if (res % i == 0)
			cnt++;
	}
	printf("%d", cnt);	// 약수 갯 수 출력

	return 0;
}

