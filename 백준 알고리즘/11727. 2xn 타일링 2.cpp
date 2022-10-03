#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<vector>
#include<queue>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    freopen("input.txt", "rt", stdin);
    int t, m, n, k;
    int dy[]{ -1,1,0,0 };
    int dx[]{ 0,0,-1,1 };

    cin >> t;
    for (int i = 0; i < t; i++)
    {
        cin >> m >> n >> k; // 가로 , 세로 , 배추개수
        vector<vector<int>> map(n, vector<int>(m, 0));
        queue<pair<int, int>> q;
        int y, x;
        int cnt = 0;

        for (int j = 0; j < k; j++)
        {
            cin >> x >> y;
            map[y][x] = 1;
        }

        for (y = 0; y < n; y++)
        {
            for (x = 0; x < m; x++)
            {
                if (map[y][x] == 1) // 배추 발견하면 인근 배추 다 체크
                {
                    cnt++;
                    map[y][x] = 0;

                    q.push(make_pair(y, x));

                    while (q.empty() == false)
                    {
                        int ty = q.front().first;
                        int tx = q.front().second;
                        q.pop();

                        for (int h = 0; h < 4; h++)
                        {
                            int ny = ty + dy[h];
                            int nx = tx + dx[h];

                            if (ny >= 0 && ny < n && nx >= 0 && nx < m && map[ny][nx] == 1)
                            {
                                q.push(make_pair(ny, nx));
                                map[ny][nx] = 0;
                            }
                        }

                    }
                }
            }
        }

        cout << cnt << endl;
    }
    return 0;
}