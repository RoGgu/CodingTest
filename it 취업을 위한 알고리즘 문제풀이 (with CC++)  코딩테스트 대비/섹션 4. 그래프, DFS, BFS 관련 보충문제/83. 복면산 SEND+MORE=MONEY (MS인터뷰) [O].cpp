#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>	// cin,cout말고 이제 c에서 제공하는 sanf, printf 사용 - 속도가 조금 더 빠름
#include<vector>
#include<queue>
#include<algorithm>

using namespace std;

// 나오는 문자에 대응되는 문자열을 만듬
// 0 1 2 3 4 5 6 7
// D E M N O R S Y

int a[8];
int ch[10];

int Send()
{
	return a[6] * 1000 + a[1] * 100 + a[3] * 10 + a[0];
}
int More()
{
	return a[2] * 1000 + a[4] * 100 + a[5] * 10 + a[1];
}
int Money()
{
	return a[2] * 10000 + a[4] * 1000 + a[3] * 100 + a[1] * 10 + a[7];
}

void DFS(int L)
{
	if (L == 8)
	{
		if (Send() + More() == Money()) // 공식일 성립하면 답인지 체크
		{
			if (a[6] != 0 && a[2] != 0) //처음 알파벳은 0이 오면 안된다.
			{
				printf("   %d  %d  %d  %d\n", a[6], a[1], a[3], a[0]);
				printf("+  %d  %d  %d  %d\n", a[2], a[4], a[5], a[1]);
				printf("----------------\n");
				printf("%d %d  %d  %d  %d\n", a[2], a[4], a[3], a[1], a[7]);
			}
		}
	}
	else
	{
		for (int i = 0; i < 10; i++) // 0~9까지 돌면서 수자 하나씩 넣어본다
		{
			if (ch[i] == 0)
			{
				a[L] = i;
				ch[i] = 1;
				DFS(L + 1);
				ch[i] = 0;
			}
		}
	}
}

int main()
{
	freopen("input.txt", "rt", stdin); // input.txt 파일 읽기
	int i, tmp;

	DFS(0);
	return 0;
}
