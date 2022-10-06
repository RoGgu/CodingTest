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
    int N, result = 0;
    cin >> N;
    vector<pair<int, int>> vp(N + 1);
    vector<int> dy(N + 2, 0);
    for (int i = 1; i <= N; i++)
    {
        cin >> vp[i].first;
        cin >> vp[i].second;
    }

    for (int i = 1; i <= N; i++)
    {
        int endDay = i + vp[i].first; // 작업 끝나는 날 기준으로 작업 보상치 값 세팅한다.
        if (endDay <= N + 1) // 퇴사 날 지나면 안됌
        {
            for (int j = endDay; j <= N + 1; j++) // 해당 작업 끝난 날 후로 퇴사 날 까지 보상치 최대로 세팅
            {
                // 보상치는 기존에 세팅된 보상치 보다 커야 세팅한다.
                dy[j] = max(dy[j], (dy[i] + vp[i].second));
                result = max(result, dy[j]);
            }
        }
    }

    cout << result;
    return 0;
}
