#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<string.h>
#include<vector>
#include<queue>
#include <unordered_map>
using namespace std;


int n, m;
int dy[] = { -1, 1, 0 , 0 };
int dx[] = { 0, 0, -1 , 1 };
int map[8][8]; // 입력 맵
int tmp[8][8]; // 벽 세우는 임시 맵
int res = 0; // 독 안개 안퍼진 최대 방 개수

void CopyMap(int a[][8], int b[][8])
{
    for (int y = 0; y < n; y++)
    {
        for (int x = 0; x < m; x++)
            a[y][x] = b[y][x];
    }
}

void BFS()
{
    int bfsMap[8][8];
    CopyMap(bfsMap, tmp); // 독 안개 퍼지는 임시 맵 세팅
    queue<pair<int, int>> q;

    for (int y = 0; y < n; y++)
    {
        for (int x = 0; x < m; x++)
        {
            if (tmp[y][x] == 2)
                q.push(make_pair(y, x));
        }
    }

    while (!q.empty())
    {
        int y = q.front().first;
        int x = q.front().second;
        q.pop();

        for (int i = 0; i < 4; i++)
        {
            int ny = y + dy[i];
            int nx = x + dx[i];

            if (0 <= ny && ny < n && 0 <= nx && nx < m)
            {
                if (bfsMap[ny][nx] == 0)
                {
                    bfsMap[ny][nx] = 2;
                    q.push(make_pair(ny, nx));
                }
            }
        }
    }

    int cnt = 0; // 0이 독 안개 안퍼진 방 개수 카운트
    for (int y = 0; y < n; y++)
    {
        for (int x = 0; x < m; x++)
        {
            if (bfsMap[y][x] == 0)
                cnt += 1;
        }
    }

    res = max(res, cnt);
}

void Wall(int cnt)
{
    if (cnt == 3) // 벽 3개 세워지면 BFS 독 안개 퍼지는거 실행
    {
        BFS();
        return;
    }
    else
    {
        for (int y = 0; y < n; y++)
        {
            for (int x = 0; x < m; x++)
            {
                if (tmp[y][x] == 0)
                {
                    tmp[y][x] = 1;
                    Wall(cnt + 1);
                    tmp[y][x] = 0;
                }
            }
        }
    }

}


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    freopen("input.txt", "rt", stdin);
    cin >> n >> m;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> map[i][j];
        }
    }

    for (int y = 0; y < n; y++)
    {
        for (int x = 0; x < m; x++)
        {
            if (map[y][x] == 0)
            {
                CopyMap(tmp, map); // 벽 새울 임시 맵 세팅
                tmp[y][x] = 1;
                Wall(1);
                tmp[y][x] = 0;
            }
        }
    }

    cout << res << endl;
    return 0;
}