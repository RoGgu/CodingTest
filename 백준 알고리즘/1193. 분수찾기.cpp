#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<string>
#include<vector>
#include<queue>
#include<algorithm>
#include<cmath>
#include<map>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	freopen("input.txt", "rt", stdin);
	int N;
	cin >> N;

	int i = 1;
	while (N > i)  // N이 몇번쨰 대각선에 속해 있는지 찾는다.
	{
		N -= i;
		i++;
	}

	// 속한 대각선이 짝수인지 홀수인지에 따라서 다르게 출력
	if (i % 2 == 1)
		cout << i + 1 - N << '/' << N << endl;
	else
		cout << N << '/' << i + 1 - N << endl;

	return 0;
}
