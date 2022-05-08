#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>

using namespace std;

struct Pos // q에 넣기위한 좌표
{
    Pos() {}
    Pos(int y, int x)
    {
        _y = y;
        _x = x;
    }

    int _y;
    int _x;
};


int main() {
    ios::sync_with_stdio(false);
    //freopen("input.txt", "rt", stdin);
    int m, n, k;
    cin >> m >> n >> k;
    vector<vector<int>> map(m, vector<int>(n, 0));
    vector<vector<int>> ch(m, vector<int>(n, 0));
    queue<Pos> q;
    int dy[4] = { -1, 1,  0, 0 };
    int dx[4] = { 0, 0, -1, 1 };
    vector<int> result;


    int x1, y1, x2, y2;
    for (int i = 0; i < k; i++)
    {
        cin >> x1 >> y1 >> x2 >> y2;
        for (int y = y1; y < y2; y++)
        {
            for (int x = x1; x < x2; x++)
            {
                map[y][x] = 1;
            }
        }
    }

    for (int y = m - 1; y >= 0; y--)
    {
        for (int x = 0; x < n; x++)
        {
            if (map[y][x] == 0) // 0이면 영역 체크해서 같은영역 전부다 1로 바꾸고 새로운 영역 기록
            {
                int cnt = 1;
                q.push(Pos(y, x));
                map[y][x] = 1;

                while (q.empty() == false) // BFS 탐색으로 해당 영역에 갯수체크하고 중복 없앤다.
                {
                    Pos pos = q.front();
                    q.pop();

                    for (int i = 0; i < 4; i++)
                    {
                        int nextY = pos._y + dy[i];
                        int nextX = pos._x + dx[i];

                        if (nextY < 0 || nextY >= m || nextX < 0 || nextX >= n)
                            continue;

                        if (map[nextY][nextX] == 0)
                        {
                            cnt++;
                            map[nextY][nextX] = 1;
                            q.push(Pos(nextY, nextX));
                        }
                    }
                }

                result.push_back(cnt);
            }
        }
    }

    cout << result.size() << endl; // 영역 갯수 출력
    sort(result.begin(), result.end()); // 영역별 범위 오름차순 정렬
    for (int i = 0; i < result.size(); i++) 
        cout << result[i] << " "; // 영역별 범위 출력


    return 0;
}