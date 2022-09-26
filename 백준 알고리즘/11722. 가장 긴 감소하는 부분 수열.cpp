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
    int n;
    cin >> n;
    vector<int>v(n);
    vector<int> dy(n, 1); // 다이나믹으로 각 수 인덱스에 감소하는 최대 수 세팅한다.
    for (int i = 0; i < n; i++)
        cin >> v[i];

    for (int i = 1; i < n; i++)
    {
        int max = 0;
        for (int j = i - 1; j >= 0; j--)
        {
            if (v[j] > v[i])
            {
                // 자기보다 큰 수이고 가장 최대 수 포함이 많은걸 선택해서 세팅한다.
                if (dy[j] > max)
                    max = dy[j];
            }
        }
        // 그 수 포함한거에 자기도 포함되니까 + 1
        dy[i] = max + 1;
    }

    // 전체 다이나믹 돌면서 감소 수가 제일 큰 걸 찾는다.
    int res = dy[0];
    for (int i = 1; i < n; i++)
    {
        res = max(res, dy[i]);
    }
    cout << res;
    return 0;
}