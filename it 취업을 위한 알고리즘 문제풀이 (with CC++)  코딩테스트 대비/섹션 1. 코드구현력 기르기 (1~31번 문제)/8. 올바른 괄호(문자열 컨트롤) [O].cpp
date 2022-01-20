#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>	// cin,cout말고 이제 c에서 제공하는 sanf, printf 사용 - 속도가 조금 더 빠름

int main() {
	freopen("input.txt", "rt", stdin); // input.txt 파일 읽기
	char a[31];	// a : 입력 값
	int i, check = 0; // for문카운트, check : 괄호체크 ( 일 때 1증가, ) 일 떄 1감소

	scanf("%s", a);

	for (i = 0; a[i] != '\0'; i++)
	{
		if (a[i] == '(')
			check++;
		else
			check--;

		if (check < 0) //마이너스가 되면 현재 열린것 보다 닫은게 더 많아서 잘못된거임
		{
			break;
		}
	}

	if (check == 0) // 정상적인 괄호라면 열고 닫는거 수 같아서 0이된다.
		printf("YES");
	else
		printf("NO");


	return 0;
}
