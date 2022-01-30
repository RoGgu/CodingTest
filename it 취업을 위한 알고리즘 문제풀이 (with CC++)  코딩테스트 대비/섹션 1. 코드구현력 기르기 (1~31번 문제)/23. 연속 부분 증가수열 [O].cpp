#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>	// cin,cout말고 이제 c에서 제공하는 sanf, printf 사용 - 속도가 조금 더 빠름
#include<vector>

int main() {
	//freopen("input.txt", "rt", stdin); // input.txt 파일 읽기
	int i, n, max = -2147000000, preNum = 0, cnt = 0; // i : for문 카운트, n : 총 배열 수, max : 최대 길이, preNum : 지금 순서의 전 숫자, cnt : 증가배열 카운트
	scanf("%d", &n);

	std::vector<int>a(n);	// 미리 할당하는 배열 말고 동적 할당 vector사용
	for (i = 0; i < n; i++) // vector에 배열 정보 입력
		scanf("%d", &a[i]);

	for (i = 0; i < n; i++)
	{
		if (a[i] >= preNum)	// 같거나 크면 증가하는거라 카운터 증가
			cnt++;
		else	// 아닐경우 다시 카운터 1부터 다시셈
			cnt = 1;

		preNum = a[i];

		if (cnt > max)	// 현재까지 증가한 수가 max보다 크면 다시 세팅
			max = cnt;
	}

	printf("%d", max);
	return 0;
}
