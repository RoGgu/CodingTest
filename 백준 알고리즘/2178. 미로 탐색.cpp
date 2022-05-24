#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<vector>
#include<queue>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    freopen("input.txt", "rt", stdin);
    int n, m, cnt = 0;
    int dy[] = { -1, 1, 0 ,0 };
    int dx[] = { 0, 0, -1 ,1 };
    cin >> n >> m;
    vector<vector<int>> dyMap(n, vector<int>(m, 0));
    vector<string> sMap(n); // 입력이 한줄로 바로 들어와서 string으로 관리
    for (int i = 0; i < n; i++)
        cin >> sMap[i];

    // BFS탐색으로 각 좌표별 이동하는데 드는 값 세팅
    dyMap[0][0] = 1;
    queue<pair<int, int>> q;
    q.push(make_pair(0, 0));

    while (q.empty() == false)
    {
        int cy = q.front().first;
        int cx = q.front().second;
        q.pop();

        for (int i = 0; i < 4; i++)
        {
            int ny = cy + dy[i];
            int nx = cx + dx[i];

            if (ny < 0 || ny >= n || nx < 0 || nx >= m)
                continue;

            if (sMap[ny][nx] == '1' && dyMap[ny][nx] == 0)
            {
                dyMap[ny][nx] = dyMap[cy][cx] + 1;
                q.push(make_pair(ny, nx));
            }
        }
    }

    cout << dyMap[n - 1][m - 1] << endl;
    return 0;
}