#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<string.h>
#include<vector>
#include<queue>
#include <unordered_map>
#include<algorithm>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    freopen("input.txt", "rt", stdin);
    int T, N;
    cin >> T;

    for (int t = 0; t < T; t++)
    {
        cin >> N;
        // 입력한 값을 다이나믹 최대값 세팅을 계속 한다.
        vector<vector<int>> dy(2, vector<int>(N + 1, 0));

        for (int i = 0; i < 2; i++)
        {
            for (int j = 1; j <= N; j++)
            {
                cin >> dy[i][j];
            }
        }

        for (int i = 2; i <= N; i++)
        {
            // 현재 가장 최대 값은 대각선 i-1 과 대각선 i-2 중에골라서 현재 값 더한게 최대값
            dy[0][i] = max(dy[1][i - 1], dy[1][i - 2]) + dy[0][i];
            dy[1][i] = max(dy[0][i - 1], dy[0][i - 2]) + dy[1][i];
        }

        cout << max(dy[0][N], dy[1][N]) << "\n";
    }

    return 0;
}