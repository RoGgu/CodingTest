#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>
#include<stack>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    freopen("input.txt", "rt", stdin);
    int n, tmp, maxNum = 0, cnt = 0, maxCnt = 1;
    cin >> n;
    vector<vector<int>> map(n, vector<int>(n));
    queue<pair<int, int>> q;
    int dy[] = { -1, 1,  0, 0 };
    int dx[] = { 0, 0, -1, 1 };

    for (int y = 0; y < n; y++)
    {
        for (int x = 0; x < n; x++)
        {
            cin >> map[y][x];
            if (map[y][x] > maxNum)
                maxNum = map[y][x];
        }
    }

    for (int h = 0; h < maxNum; h++)
    {
        cnt = 0;
        vector<vector<int>> ch(n, vector<int>(n, 0));
        for (int y = 0; y < n; y++)
        {
            for (int x = 0; x < n; x++)
            {
                if (map[y][x] > h && ch[y][x] == 0)
                {
                    cnt++;
                    q.push(make_pair(y, x));
                    ch[y][x] = 1;
                    while (q.empty() == false)
                    {
                        int cy = q.front().first;
                        int cx = q.front().second;
                        q.pop();

                        for (int i = 0; i < 4; i++)
                        {
                            int ny = cy + dy[i];
                            int nx = cx + dx[i];

                            if (ny >= 0 && ny < n && nx >= 0 && nx < n)
                            {
                                if (map[ny][nx] > h && ch[ny][nx] == 0)
                                {
                                    q.push(make_pair(ny, nx));
                                    ch[ny][nx] = 1;
                                }
                            }
                        }
                    }
                }
            }
        }

        if (cnt > maxCnt)
            maxCnt = cnt;
    }

    cout << maxCnt << endl;
    return 0;
}
