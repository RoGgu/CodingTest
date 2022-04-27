#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>	// cin,cout말고 이제 c에서 제공하는 sanf, printf 사용 - 속도가 조금 더 빠름
#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
#include<cstdlib>

using namespace std;

// 최대 선 연결하기

// 교차되지 않는 선을 연결해서 최대 연결된 선의 수 구하기
// LIS 응용해서 푼다.

// 오른쪾 해당 수마다 dy 를 구해놓는다
// dy중 가장 큰 수를 최대 연결의 수로 답 추출

// 4번 문제 최대 부분 증가수열과 코드가 똑같다.

// 만약 모든 선 다 연결해두고 최소의 선만 제거하면 교차하지 않는 선 구하는 문제면
// - 모든 연결 선 - 최대 연결된 선의 수를 하면 제거해야할 문제의 선분 수가 나온다.

int main()
{
	//freopen("input.txt", "rt", stdin);
	int n, tmp, max = -2147000000;
	cin >> n;
	vector<int> v(n + 1);
	vector<int> dy(n + 1);
	for (int i = 1; i <= n; i++)
	{
		cin >> tmp;
		v[i] = tmp;
	}

	dy[1] = 1;

	for (int i = 2; i <= n; i++)
	{
		int cnt = 0;
		for (int j = i - 1; j >= 1; j--)
		{
			if (v[i] > v[j] && dy[j] > cnt)
			{
				cnt = dy[j];
			}
		}

		dy[i] = cnt + 1;
		if (dy[i] > max)
			max = dy[i];
	}

	cout << max << endl;
	return 0;
}

