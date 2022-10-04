#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<string>
#include<vector>
#include<stack>
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
	int N, a, b;
	int result = 0;
	cin >> N;

	vector<pair<int, int>> vp;
	vp.emplace_back(0, 0);
	vector<int> dp(102, 1);

	for (int i = 0; i < N; i++)
	{
		cin >> a >> b;
		vp.emplace_back(a, b);
	}
	sort(vp.begin(), vp.end());


	for (int i = 2; i <= N; i++)
	{
		for (int j = 1; j < i; j++)
		{
			// 도착 연결 선이 i 도착선 보다 작아야 겹치지 않고 연결할 수 있다.
			if (vp[j].second < vp[i].second)
			{
				// 현재 j에 연결된 최대 선의 개수가 i에 보다 더 많을 경우 j포함해서 연결, i도 연결되니까 j최대개수 + 1 로 세팅
				if (dp[j] >= dp[i])
					dp[i] = dp[j] + 1;
			}
		}
		result = max(result, dp[i]); // 현재 연결된 최대 선의 개수
	}

	// 총 선의 개수 - 현재 연결 가능한 최대 선의 개수가 = 제거해야할 선에 개수이다.
	cout << N - result << endl;
	return 0;
}