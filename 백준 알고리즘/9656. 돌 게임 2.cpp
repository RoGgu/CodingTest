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

int dp[1001];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    freopen("input.txt", "rt", stdin);
    int N;
    cin >> N;

    // 0 : 창근이 승, 1 : 상근이 승
    dp[1] = 0;
    dp[2] = 1;
    dp[3] = 0;

    for (int i = 4; i <= N; i++)
    {
        // i - 1 혹은 i - 3 의 턴인 사람이 무조건 지도록 되어 있어서 해당 턴이 아닌 사람이 i번쨰에 이긴다.
        if (dp[i - 1] == 0 || dp[i - 3] == 0) // i-1, i-3이 상근이 턴이라 i번째엔 창근이가 이긴다.
            dp[i] = 1;
        else
            dp[i] = 0;
    }


    if (dp[N] == 1)
        cout << "SK";
    else
        cout << "CY";

    return 0;
}
