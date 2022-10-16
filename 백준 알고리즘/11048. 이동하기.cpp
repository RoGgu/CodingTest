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
    int n, m;
    cin >> n >> m;
    vector<vector<int>> miro(n + 1, vector<int>(m + 1, 0));

    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
            cin >> miro[i][j];

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            // 현재 위치까지 왔을 때 최대 들고있는 코인 수 
            int prevMaxCoin = max(max(miro[i - 1][j], miro[i][j - 1]), miro[i - 1][j - 1]);
            // 최대 들 수 있는 코인 수 + 현재 위치에서 획득하는 코인 수
            miro[i][j] = miro[i][j] + prevMaxCoin;
        }
    }
    cout << miro[n][m]; // 마지막 최종 목적지에 최대 들고 있는 코인 수 값이 세팅되어 있다.
    return 0;
}
