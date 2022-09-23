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
    int n, m, totalCost = 0;
    cin >> n >> m;
    vector<int> memory(n + 1);
    vector<int> cost(n + 1);

    for (int i = 1; i <= n; i++)
        cin >> memory[i];
    for (int i = 1; i <= n; i++)
    {
        cin >> cost[i];
        totalCost += cost[i];
    }
    vector<vector<int>> dp(n + 1, vector<int>(totalCost + 1, 0));

    // dp[i][j] 는 i 번째 앱까지 탐색했을 경우 j비용을 소모해서 얻을 수 있는 최대 메모리 값이 세팅되어 있다.
    for (int i = 1; i <= n; i++)
    {
        for (int j = 0; j <= totalCost; j++)
        {
            if (j - cost[i] >= 0) // i의 cost 지불가능하다면 그 전 탐색이랑 비교해서 현재 i 번쨰 앱 지울때 메모리가 더 큰지 비교해서 세팅
                dp[i][j] = max(dp[i][j], dp[i - 1][j - cost[i]] + memory[i]);

            // i-1 번쨰 꺼랑 현재 세팅 값이랑 비교
            dp[i][j] = max(dp[i][j], dp[i - 1][j]);
        }
    }

    // n만큼 탐색 즉 모든 앱 탐색끝나면
    // dy[n][j] 에는 j 만큼의 비용을 소모할경우 최대 메모리 값이 세팅되어있다.
    for (int i = 0; i <= totalCost; i++)
    {
        // m 메모리 용량 넘는 순간이 최소 비용이다.
        if (dp[n][i] >= m)
        {
            cout << i;
            break;
        }
    }
    return 0;
}