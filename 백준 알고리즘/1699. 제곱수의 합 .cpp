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

int arr[100001];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    freopen("input.txt", "rt", stdin);
    int N;
    cin >> N;


    int dp[100001]; // 각 수의 최소 제곱수의 숫자 세팅.
    for (int i = 1; i <= N; i++)
    {
        dp[i] = i; // 최대 1의 제곱으로 한 수가 기본 값

        // 더할 수 있는 제곱수 다 구해서 최소 수 구한다.
        for (int j = 1; j * j <= i; j++)
        {
            dp[i] = min(dp[i], dp[i - j * j] + 1);
        }
    }
    cout << dp[N];
    return 0;
}