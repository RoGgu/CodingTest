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
    int N, M;
    cin >> N;
    vector<int> v(N + 1, 0);
    vector<int> dp(N + 1, 0); // 인덱스 까지의 수의 합을 저장한다

    for (int i = 1; i <= N; i++)
    {
        cin >> v[i];
        dp[i] = dp[i - 1] + v[i];
    }

    cin >> M;
    int s, e;
    for (int i = 0; i < M; i++)
    {
        cin >> s >> e;
        // dp[e] - dp[s-1] 의 값은 s 부터 e까지의 합이 나온다
        cout << (dp[e] - dp[s - 1]) << "\n";
    }
    return 0;
}
