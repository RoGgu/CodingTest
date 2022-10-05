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
    int T;
    cin >> T;
    for (int t = 0; t < T; t++)
    {
        int N;
        cin >> N;
        vector<int> v(N);
        for (int i = 0; i < N; i++)
            cin >> v[i];
        int M;
        cin >> M;

        vector<int> dp(M + 1, 0); // [idnex]에 값은 해당 값을 만들 수 있는 최대 방법 수 이다.
        dp[0] = 1; // 0원을 만드는 방법은 동전 아무것도 안 쓰는 1개 뿐이다.

        for (int i = 0; i < N; i++) // 동전 개수만큼 반복
        {
            for (int j = v[i]; j <= M; j++)
            {
                // 현재 동전을 더해서 j값을 만들려면 j-v[i]에 값이 필요하다
                // 그전 동전으로 만들 수 있는 최대 수 dp[j]에 값에 현재 동전 더하기 전에 dp[j-v[i]]에 최대 수를 더해서 값 세팅한다.
                dp[j] = dp[j] + dp[j - v[i]];
            }
        }

        cout << dp[M] << "\n";
    }
    return 0;
}
