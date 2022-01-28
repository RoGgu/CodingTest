#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>	// cin,cout말고 이제 c에서 제공하는 sanf, printf 사용 - 속도가 조금 더 빠름
#include<vector>


int main() {
	//freopen("input.txt", "rt", stdin); // input.txt 파일 읽기
	int i, n, day, max = -2147000000, sum = 0; // i : for문 카운트, n : 총 갯수, day : 온도 재는연속날짜, max : 제일 높은 연속날짜온도, sum : 온도합 계산
	scanf("%d", &n);
	scanf("%d", &day);

	std::vector<int>a(n);	// 미리 할당하는 배열 말고 동적 할당 vector사용
	for (i = 0; i < n; i++) // vector에 온도 정보 입력
		scanf("%d", &a[i]);

	for (i = 0; i < day; i++) // 처음 온도합 재는곳까지 일단 계산
	{
		sum += a[i];
	}
	max = sum;	// 일단 max는 처음 나온 온도의 합

	for (i = day; i < n; i++)	// 제일 오래된 날짜온도 빼고 새로운 날짜 온도 더하고 max비교
	{
		sum = sum + a[i] - a[i - day];
		if (sum > max)
			max = sum;
	}

	printf("%d", max);
	return 0;
}
