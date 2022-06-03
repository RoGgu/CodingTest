#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include <string.h>
#include<vector>
#include<queue>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    freopen("input.txt", "rt", stdin);
    int n;
    cin >> n;
    vector<int>dp(n + 1, 0);
    dp[1] = 1; //dp를  제곱근의 갯수 중 제일 작은 개수로 되는걸로 세팅

    for (int i = 2; i <= n; i++)
    {
        int minn = 2147000000;
        for (int j = 1; j * j <= i; j++)
        {
            int tmp = i - j * j;
            minn = min(minn, dp[tmp]);
        }
        dp[i] = minn + 1;
    }
    cout << dp[n];
    return 0;
}