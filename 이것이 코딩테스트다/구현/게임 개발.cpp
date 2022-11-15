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
    int n, m, res = 1;
    cin >> n >> m;
    int x, y, direction;
    cin >> x >> y >> direction;
    vector<vector<int>> map(n, vector<int>(m, 0));
    vector<vector<int>> chMap(n, vector<int>(m, 0)); // 이미 간 곳 체크하기위한 체크 맵

    int dy[4] = { -1, 0, 1, 0 };
    int dx[4] = { 0, 1, 0, -1 };

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
            cin >> map[i][j];
    }

    chMap[y][x] = 1; // 시작지점 간 걸로 미리 체크
    while (true)
    {
        int ny = -1;
        int nx = -1;
        bool isMove = false;

        for (int i = 0; i < 4; i++)
        {
            direction = (direction - 1 + 4) % 4; // 왼쪽으로 회전한 이동 방향

            // 회전 후 이동했을 때 예상 위치
            ny = y + dy[direction];
            nx = x + dx[direction];

            // 이동가능 곳이면 이동한다.
            if (map[ny][nx] == 0 && chMap[ny][nx] == 0)
            {
                y = ny;
                x = nx;
                isMove = true;
                res += 1;
                chMap[ny][nx] = 1;
                break;
            }
        }

        // 네 방향 다 갈 수 없으면 원래 바라보던 방향에서 뒤로 한 칸 간다.
        if (isMove == false)
        {
            // 만약 뒤에 칸이 바다면 이동 종료
            if (map[ny][nx] == 1)
                break;

            y = y - dy[direction];
            x = x - dx[direction];

        }
    }

    cout << res;
    return 0;
}