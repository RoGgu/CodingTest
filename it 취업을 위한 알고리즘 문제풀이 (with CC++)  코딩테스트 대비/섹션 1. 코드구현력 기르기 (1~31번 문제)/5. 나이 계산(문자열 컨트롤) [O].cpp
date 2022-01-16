#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>	// cin,cout말고 이제 c에서 제공하는 sanf, printf 사용 - 속도가 조금 더 빠름
//#include<iostream>

using namespace std;
int main() {
	/reopen("input.txt", "rt", stdin); // input.txt 파일 읽기
	char a[20];	// 주민등록 번호
	int year, age;	// year : 출생연도, age : 실제 나이

	scanf("%s", &a);	// 주민등록 번호 얻어옴
	if (a[7] == '1' || a[7] == '2')	// 뒤에 첫번쨰 자리가 1,또는2면 1900년대생
	{
		year = 1900 + ((a[0] - 48) * 10 + (a[1] - 48));	// a[0], a[1]이 숫자로 보여도 아스키 코드값 48~57 까지라서 48빼줘야 진짜 숫자 값
	}
	else
	{
		year = 2000 + ((a[0] - 48) * 10 + (a[1] - 48));
	}

	age = 2019 - year + 1;
	printf("%d ", age);
	if (a[7] == '1' || a[7] == '3')	// 뒷자리 첫 번쨰 수로 성별 비교
		printf("M");
	else
		printf("W");

	return 0;
}
