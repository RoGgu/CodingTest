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
    int n, tmpCnt = 0, maxCnt = 0;
    cin >> n;
    vector<int> v(n + 1, 0); // 박스 크기
    vector<int> dp(n + 1, 0); // 각 박스별 최대 포함하는 상자 수
    dp[1] = 1;

    for (int i = 1; i <= n; i++)
    {
        cin >> v[i];

        tmpCnt = 0; // 현재 박스에 넣을 수 있는 최대 포함 수를 체크한다
        for (int j = i - 1; j > 0; j--)
        {
            if (v[j] < v[i]) // 자기보다 작은 박스만 넣을 수 있다
            {
                // 다이나믹 프로그래밍으로 최대 개수로 넣을 수 있는 박스 찾아서 수 체크
                if (dp[j] > tmpCnt)
                {
                    tmpCnt = dp[j];
                }
            }

            // 해당 수에 자기 포함해서 + 1
            dp[i] = tmpCnt + 1;

            // 전체적으로 최대 포함하는 박스 수
            if (dp[i] > maxCnt)
            {
                maxCnt = dp[i];
            }
        }
    }

    cout << maxCnt;
    return 0;
}
