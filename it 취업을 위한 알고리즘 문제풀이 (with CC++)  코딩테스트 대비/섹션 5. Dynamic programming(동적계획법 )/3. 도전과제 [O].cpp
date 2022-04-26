#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>	// cin,cout말고 이제 c에서 제공하는 sanf, printf 사용 - 속도가 조금 더 빠름
#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
#include<cstdlib>

using namespace std;

// 도전과제 두 문제 풀이 코드


//도전과제: 계단오르기(Top - Down : 메모이제이션)
vector<int> dfsDy;
int DFS(int value)
{
	if (value == 1 || value == 2)
	{
		return value;
	}
	else
	{
		dfsDy[value] = DFS(value - 1) + DFS(value - 2);
		return dfsDy[value];
	}
}

int main()
{
	freopen("input.txt", "rt", stdin);
	int n;
	cin >> n;
	dfsDy.resize(n + 1);

	int result = DFS(n);

	cout << result;
	return 0;
}


// 도전과제 : 돌다리 건너기(Bottom-Up)

//int main()
//{
//	//freopen("input.txt", "rt", stdin); // input.txt 파일 읽기
//	int n;
//	cin >> n;
//	n++;
//	vector<int> dy(n + 1);
//	dy[1] = 1;
//	dy[2] = 2;
//
//	for (int i = 3; i <= n; i++)
//	{
//		dy[i] = dy[i - 1] + dy[i - 2];
//	}
//
//	cout << dy[n];
//	return 0;
//}
