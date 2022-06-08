#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<string.h>
#include<vector>
#include<algorithm>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    freopen("input.txt", "rt", stdin);
    int n, res = 0;
    cin >> n;
    vector<int> v(n);
    vector<int> dp(n, 1); // 해당 인덱스에 증가 수열 개수 세팅
    for (int i = 0; i < n; i++)
        cin >> v[i];

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < i; j++)
        {
            if (v[i] > v[j])
            {
                if (dp[i] < dp[j] + 1)
                    dp[i] = dp[j] + 1;
            }
        }

        res = max(res, dp[i]);
    }

    cout << res << endl;
    return 0;
}