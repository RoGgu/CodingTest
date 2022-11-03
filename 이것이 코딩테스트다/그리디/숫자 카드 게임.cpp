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
    int n, m, res = -2147000000;
    cin >> n >> m;
    vector<vector<int>> cards(n, vector<int>(m));
    for (int i = 0; i < n; i++)
    {
        int minNum = 2147000000;
        for (int j = 0; j < m; j++)
        {
            cin >> cards[i][j];
            // 현재 행의 가장 작은 수 탐색
            minNum = min(minNum, cards[i][j]);
        }

        // 세팅된 수랑 현재 행에서 가장 작은수랑 비교해서 큰 수 세팅
        res = max(res, minNum);
    }
    // 전체 행중에 가장 작은수 중 제일 큰 행의 수 세팅
    cout << res;
    return 0;
}