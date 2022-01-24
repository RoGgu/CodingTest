#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>	// cin,cout말고 이제 c에서 제공하는 sanf, printf 사용 - 속도가 조금 더 빠름

int main() {
	//freopen("input.txt", "rt", stdin); // input.txt 파일 읽기
	char a[101];	// 자연수 100자리 수 이상을 숫자형으로 읽을 수 없어서 문자열로 읽음
	int i, digit, max = -2147000000, result = 0;
	int numCounts[10] = { 0 };	// 인덱스에 해당하는 숫자가 몇개인지 체크하는 배열
	scanf("%s", a);

	for (i = 0; a[i] != '\0'; i++)
	{
		digit = (a[i] - 48);
		numCounts[digit]++;
	}

	for (i = 1; i <= 9; i++)
	{
		if (numCounts[i] >= max)
		{
			max = numCounts[i];
			result = i;
		}
	}

	printf("%d", result);

	return 0;
}
