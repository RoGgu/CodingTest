#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>	// cin,cout말고 이제 c에서 제공하는 sanf, printf 사용 - 속도가 조금 더 빠름
//#include<iostream>

using namespace std;
int main() {
	//freopen("input.txt", "rt", stdin); // input.txt 파일 읽기
	int n, i, max, result = 0;	// n :학생 수, i : for문 카운트, max : 현재까지 가장 키가 큰 값, result : 분노 유발자 수
	int num[101];

	scanf("%d", &n);
	for (i = 0; i < n; i++)
	{
		scanf("%d", &num[i]);
	}

	max = num[n - 1]; // 맨 끝 수를 최댓값으로 설정

	for (i = n - 1; i > 0; i--)	// 맨끝부터 돌면서 최댓값 보다 큰경우 카운터세고 최댓값 갱신
	{
		if (num[i] > max)
		{
			result++;
			max = num[i];
		}
	}

	printf("%d", result);
	return 0;
}
