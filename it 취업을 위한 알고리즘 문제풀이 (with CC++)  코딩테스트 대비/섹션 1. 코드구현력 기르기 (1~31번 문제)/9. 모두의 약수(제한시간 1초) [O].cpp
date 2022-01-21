#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>	// cin,cout말고 이제 c에서 제공하는 sanf, printf 사용 - 속도가 조금 더 빠름

using namespace std;
int main() {
	//freopen("input.txt", "rt", stdin); // input.txt 파일 읽기
	int cnt[50001] = { 0 };	// 1부터 돌면서 자신의 배수에 자기가 약수로 속하니까 약수 갯수 하나씩 추가할 배열
	int n, i, j; // n : 입력 수 , for문 카운터 i , j
	scanf("%d", &n);

	for (int i = 1; i <= n; i++)
	{
		for (int j = i; j <= n; j = j + i) // i의 배수 돌면서 더해준다
		{
			cnt[j]++;
		}
	}

	for (int i = 1; i <= n; i++)	// 총 더해진 약수의 갯 수 출력
		printf("%d ", cnt[i]);

	return 0;
}
