#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>	// cin,cout말고 이제 c에서 제공하는 sanf, printf 사용 - 속도가 조금 더 빠름
//#include<iostream>

using namespace std;
int main() {
	//freopen("input.txt", "rt", stdin); // input.txt 파일 읽기
	int n, i, temp; // n : 총 횟수, i : for문 카운트, temp : 가위바위보 결과 값
	int a[101], b[101]; // a : a가 낸것들, b : b가 낸것들
	scanf("%d", &n);

	for (i = 0; i < n; i++)
		scanf("%d", &a[i]);

	for (i = 0; i < n; i++)
		scanf("%d", &b[i]);

	for (i = 0; i < n; i++) // 매 회마다 비교해서 가위바위보 승리공식으로 계산
	{
		temp = a[i] - b[i];
		if (temp < 0)
			temp += 3;

		if (temp == 0)
			printf("D\n");
		else if (temp == 1)
			printf("A\n");
		else
			printf("B\n");
	}

	return 0;
}
