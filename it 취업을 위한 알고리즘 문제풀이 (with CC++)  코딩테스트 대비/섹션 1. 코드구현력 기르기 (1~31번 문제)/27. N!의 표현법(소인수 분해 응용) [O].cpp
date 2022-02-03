#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>	// cin,cout말고 이제 c에서 제공하는 sanf, printf 사용 - 속도가 조금 더 빠름
#include<vector>
#include<algorithm>

using namespace std;
int main()
{
	//freopen("input.txt", "rt", stdin); // input.txt 파일 읽기
	int i, j, n, temp; // i: for문 카운트, j : 소인수 나누기, n : 입력 수, temp : 소인수로 나눈 후 값
	scanf("%d", &n);
	vector<int> ch(n + 1); // 소인수 개수 체크 배열

	for (i = 2; i <= n; i++)
	{
		temp = i;
		j = 2;
		while (true)
		{
			if (temp % j == 0)	// 2부터 나누면서 소인수 개수 체크
			{
				temp = temp / j;
				ch[j]++;
			}
			else
				j++;

			if (temp == 1) // 1이면 이미 다나눠진거라서 다음수로 넘어감
				break;
		}
	}

	printf("%d! = ", n);
	for (i = 2; i <= n; i++)
	{
		if (ch[i] != 0)
			printf("%d ", ch[i]);
	}

	return 0;
}
