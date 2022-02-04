#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>	// cin,cout말고 이제 c에서 제공하는 sanf, printf 사용 - 속도가 조금 더 빠름
#include<algorithm>

using namespace std;
int main() {
	//freopen("input.txt", "rt", stdin); // input.txt 파일 읽기
	int i, n, temp, count = 0; // i : for문 카운트, n : 입력 수, temp : 현재 3체크 수, count 총 3의 개수
	scanf("%d", &n);

	for (i = 3; i <= n; i++)
	{
		temp = i;
		while (temp > 0)
		{
			if (temp % 10 == 3)	// 나머지가 3이면 3이있는거니까 체크
				count++;
			temp = temp / 10;	// 한자리씩 확인하면서 넘어간다.
		}
	}

	printf("%d", count);
	return 0;
}
