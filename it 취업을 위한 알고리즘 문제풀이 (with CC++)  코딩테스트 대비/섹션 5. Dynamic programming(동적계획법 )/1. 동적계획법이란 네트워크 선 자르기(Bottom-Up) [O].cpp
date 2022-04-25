#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>	// cin,cout말고 이제 c에서 제공하는 sanf, printf 사용 - 속도가 조금 더 빠름
#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
#include<cstdlib>

using namespace std;



// 동적계획법
// Bottom-UP
// 작은 범위에 맞는 식을 써서 답을 구한 후
// 작은 범위 즉 앞에 미리 구한답을 사용해서 
// 점점 범위를 확장시켜서 큰 범위에 답도 빠르게 구할 수 있는 방식

// 현재 문제는 선에 현재 남은길이에 구할 수 있는 방법을 한번 구할때마다 세팅해놔서
// 만약 선길이가 5 남았다면 dx[5]에 경우의 수를 한번 구할 때 넣어 두고
// 다음에 또 5가 남았을때는 dx[5]에 값을 바로 사용해서 두번 구하지 않게 한다.

// 직관적으로 바로 알 수 있는건 미리 값을 넣어둔다 ex) dy[1] = 1, dy[2] = 2




vector<int>dy; // 미리 구해진 동적 값 구해서 넣어둔다.

int main()
{
	//freopen("input.txt", "rt", stdin); // input.txt 파일 읽기
	int n;
	cin >> n;
	dy.resize(n + 1);
	dy[1] = 1; // 1하고 2는 바로 구해져서 값을 넣어둔다.
	dy[2] = 2;

	for (int i = 3; i <= n; i++)
	{
		dy[i] = dy[i - 2] + dy[i - 1];
	}

	cout << dy[n] << endl;;
	return 0;
}

// 내가 만든 DFS방식 - 강사는 그냥 for문 하나로 끝넀다... 후,....
int DFS(int value)
{
	if (value < 0)
		return 0;

	if (value == 0)
	{
		return 1;
	}
	else if (dy[value] != 0)
		return dy[value];
	else
	{
		int tmp = 0;
		if (value - 1 >= 0)
		{
			tmp += DFS(value - 1);
		}
		if (value - 2 >= 0)
		{
			tmp += DFS(value - 2);
		}
		dy[value] = tmp;
		return dy[value];
	}
}