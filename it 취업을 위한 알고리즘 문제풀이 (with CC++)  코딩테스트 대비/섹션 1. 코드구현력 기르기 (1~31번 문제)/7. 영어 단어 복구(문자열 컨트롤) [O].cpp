#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>	// cin,cout말고 이제 c에서 제공하는 sanf, printf 사용 - 속도가 조금 더 빠름

int main() {
	freopen("input.txt", "rt", stdin); // input.txt 파일 읽기
	char a[101];	// a: 입력 값
	char res[101];	// 정답 소문자화 문자열
	int i, lenght = 0; // i: for문 카운터, lenght : res의 길이

	// scanf는 띄어쓰기가 있으면 끊겨서 세팅한다
	//scanf("%s", a);
	gets_s(a);	// 그래서 gets_s 쓰면 '\n' 줄바꿈 나올떄가지의 데이터 정보 받아옴

	for (i = 0; a[i] != '\0'; i++)
	{
		if (a[i] != ' ')
		{
			if (a[i] >= 65 && a[i] <= 90) // 대문자 소문자화 아스키코드값 더해줌
			{
				res[lenght] = a[i] + 32;
			}
			else
			{
				res[lenght] = a[i];
			}
			lenght++;
		}
	}
	res[lenght] = '\0'; // res의 마지막지점을 나타낼려고 \0 넣어줌

	printf("%s", res);

	return 0;
}
