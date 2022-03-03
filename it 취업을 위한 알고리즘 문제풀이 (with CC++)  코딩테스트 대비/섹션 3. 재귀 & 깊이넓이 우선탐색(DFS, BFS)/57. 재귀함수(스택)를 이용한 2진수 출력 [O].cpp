#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>	// cin,cout말고 이제 c에서 제공하는 sanf, printf 사용 - 속도가 조금 더 빠름
#include<vector>
#include<algorithm>

using namespace std;

void recur(int x) // 재귀 함수
{
	if (x == 0)
		return;
	recur(x / 2);
	printf("%d", x % 2);
}

int main()
{
	//freopen("input.txt", "rt", stdin); // input.txt 파일 읽기
	int n;
	scanf("%d", &n);
	recur(n);
	return 0;
}
