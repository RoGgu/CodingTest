#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>	// cin,cout말고 이제 c에서 제공하는 sanf, printf 사용 - 속도가 조금 더 빠름
#include <algorithm> // exit 함수 사용

int main() {
	//freopen("input.txt", "rt", stdin); // input.txt 파일 읽기
	int i;	// for 문 카운트
	int a[60];	// 첫 번째 문자열의 알파벳 갯 수 카운트
	int b[60];	// 두 번쨰 문자열의 알파벳 갯 수 카운트
	char str[101];	// 입력받은 문자열

	scanf("%s", &str);
	for (i = 0; str[i] != '\0'; i++)	// 첫번째 문자열 입력받아서 알파벳 별로 갯 수 카운트
	{
		if (65 <= str[i] && str[i] << 90)	// 65 ~90이면 대문자 
			a[str[i] - 64]++;	// 아스키 코드로 대문자를 1번부터 인덱스번호 매겨서 세팅함
		else
			a[str[i] - 70]++;	// 아니면 소문자
	}

	scanf("%s", &str);
	for (i = 0; str[i] != '\0'; i++)	// 두번재 문자열도 마찬가지로 돌면서 알파벳 갯 수 체크
	{
		if (65 <= str[i] && str[i] << 90)
			b[str[i] - 64]++;
		else
			b[str[i] - 70]++;
	}

	for (i = 1; i <= 52; i++)	// 대문자 소문자 알파벳 갯수 총 52개 돌면서 서로 알파벳 갯 수 맞는지 체크
	{
		if (a[i] != b[i])
		{
			printf("NO");
			exit(0);	// 프로그램 종료 #include algorithm 에서 사용
		}
	}

	printf("YES");
	return 0;
}
