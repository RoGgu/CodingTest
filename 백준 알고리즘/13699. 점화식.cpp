#define _CRT_SECURE_NO_WARNINGS
#include<iostream>

using namespace std;

long long dp[36]; // 숫자 범위생각해서 long long 타입 선언

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    freopen("input.txt", "rt", stdin);
    int n;
    cin >> n;

    dp[0] = 1; // 0일 경우 1이다

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= i; j++)
        {
            dp[i] += dp[j - 1] * dp[i - j]; // 점화식 그대로 공식으로 풀이
        }
    }

    cout << dp[n];
    return 0;
}
