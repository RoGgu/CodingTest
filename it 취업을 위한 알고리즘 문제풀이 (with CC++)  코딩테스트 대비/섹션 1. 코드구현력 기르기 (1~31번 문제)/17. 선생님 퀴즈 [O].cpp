#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>	// cin,cout말고 이제 c에서 제공하는 sanf, printf 사용 - 속도가 조금 더 빠름

int main() {
	//freopen("input.txt", "rt", stdin); // input.txt 파일 읽기
	int n, num, answer, i, sum;	// n : 학생 수, num : N까지의 합 할떄 N, answer : 학생 제출 답, i : for문 카운트, sum : N수까지의 합
	scanf("%d", &n);

	for (i = 0; i < n; i++)
	{
		scanf("%d %d", &num, &answer);
		sum = (num * (num + 1)) / 2;	// n까지의 수의 합 공식 :  n(n+1)/2
		if (sum == answer)
			printf("YES\n");
		else
			printf("NO\n");
	}

	return 0;
}
