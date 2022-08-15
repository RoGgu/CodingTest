#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<string>
#include<vector>
#include<queue>
#include<algorithm>
#include<cmath>
using namespace std;

int N;
int arr[101];
long long dp[101][21];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    freopen("input.txt", "rt", stdin);
    long long res;

    cin >> N;
    for (int i = 1; i <= N; i++)
    {
        cin >> arr[i];
    }

    dp[1][arr[1]] = 1; // 처음 수 가 가지느 경우의 수는 1 고정이다.
    for (int i = 2; i <= N - 1; i++)
    {
        for (int j = 0; j <= 20; j++)
        {
            if (dp[i - 1][j] == 0) // 현재 j 값에 해당하는 경우의 수 가 없으면 넘어간다.
                continue;

            if (j + arr[i] <= 20) // 더한 수의 범위가 20을 넘지 않아야 한다.
            {
                dp[i][j + arr[i]] += dp[i - 1][j]; // j에서 arr[i]를 더 한 경우의 수는 이미 j 값을 가지는 경우가 다 더해져서 세팅
            }

            if (j - arr[i] >= 0) // 뺸 수 가 음수가 아니여야 한다.
            {
                dp[i][j - arr[i]] += dp[i - 1][j]; // 위랑 똑같은데 빼는 걸로 적용
            }
        }
    }

    res = dp[N - 1][arr[N]];
    cout << res;
    return 0;
}
