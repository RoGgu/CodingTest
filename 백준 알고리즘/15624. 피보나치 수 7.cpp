#define _CRT_SECURE_NO_WARNINGS
#include<iostream>

using namespace std;

long long dp[1000001];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    freopen("input.txt", "rt", stdin);
    long long n, res;
    cin >> n;
    dp[0] = 0;
    dp[1] = 1;

    for (int i = 2; i <= n; i++)
    {
        // 다이나믹 프로그래밍으로 세팅 한값으로 피보나치 수열 계산
        // 조건에 맞춰 1000000007의 나머지 값 세팅해야 한다
        dp[i] = (dp[i - 1] + dp[i - 2]) % 1000000007;
    }

    cout << dp[n];
    return 0;
}
