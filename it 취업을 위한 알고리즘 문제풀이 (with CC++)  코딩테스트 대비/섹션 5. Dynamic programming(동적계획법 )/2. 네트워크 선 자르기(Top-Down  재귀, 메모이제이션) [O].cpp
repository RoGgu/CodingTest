#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>	// cin,cout말고 이제 c에서 제공하는 sanf, printf 사용 - 속도가 조금 더 빠름
#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
#include<cstdlib>

using namespace std;



// 동적계획법
// Top-Down : 재귀, 메모이제이션
// DFS(value)에 가지쳐서 값을 구할 때 dy[value]에 해당 DFS(value)에 값을 세팅한다.
// 그다음에 만약 같은 DFS(value)를 가지 타고 나간다면 이미 구해진 dy[value]에 값을 리턴해서 그 밑에 가지를 뻗어나갈 필요가 없다

vector<int>dy; // 미리 구해진 동적 값 구해서 넣어둔다.

int DFS(int value)
{
	if (value == 1 || value == 2) // 1과 2는 각각 1의값과 2의값을 바로 가지는게 보여서 리턴해줌
		return value;

	if (dy[value] != 0) // 이미 구해진 DFS면 값을 다시 가지쳐서 뻗어나가서 구할 필요가 없다.
		return dy[value];
	else
	{
		dy[value] = DFS(value - 1) + DFS(value - 2);
		return dy[value];
	}
}

int main()
{
	//freopen("input.txt", "rt", stdin); // input.txt 파일 읽기
	int n;
	cin >> n;
	dy.resize(n + 1);

	cout << DFS(n) << endl;;
	return 0;
}
