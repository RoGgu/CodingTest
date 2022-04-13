#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>	// cin,cout말고 이제 c에서 제공하는 sanf, printf 사용 - 속도가 조금 더 빠름
#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>

using namespace std;

// 조합 구하기 nCr
// ex) 6C4 = 6개의 수중 4개의 수 조합
// 조합 구하는 코드는 많이 쓰여서 외우는것도 좋다.

int n, r;
int ch[20]; // 조합배열

void DFS(int s, int L)
{
	if (L == r) // 원하는 조합의 원소 갯수가 충족되면 되면 출력한다
	{
		for (int i = 0; i < r; i++)
		{
			cout << ch[i] << " ";
		}
		cout << endl;
	}
	else
	{
		for (int i = s; i < n; i++)
		{
			ch[L] = i;
			DFS(i + 1, L + 1);
		}
	}
}

int main()
{
	freopen("input.txt", "rt", stdin); // input.txt 파일 읽기
	cin >> n >> r;
	DFS(0, 0);


	return 0;
}
