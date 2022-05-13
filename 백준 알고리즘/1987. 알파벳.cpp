#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>

using namespace std;


int R, C;
vector<vector<char>> map(R, vector<char>(C));
vector<int> visit(26);
int dy[] = { 0,  0, -1, 1 };
int dx[] = { 1,  -1,  0, 0 };
int maxCnt = 1; // 처음 0,0도 1로 카운트 되어야 한다.

void DFS(int y, int x, int cnt)
{
    int idx = map[y][x] - 65;
    visit[idx] = 1;

    for (int i = 0; i < 4; i++)
    {
        int ny = y + dy[i];
        int nx = x + dx[i];

        if (ny < 0 || ny >= R || nx < 0 || nx >= C)
            continue;

        int nIdx = map[ny][nx] - 65;
        if (visit[nIdx] == 0) // 방문하지 않은 알파벳만 탐색
        {
            if (cnt + 1 > maxCnt)
                maxCnt = cnt + 1;
            DFS(ny, nx, cnt + 1);
        }
    }

    visit[map[y][x] - 65] = 0;
}

int main() {
    ios::sync_with_stdio(false);
    freopen("input.txt", "rt", stdin);

    cin >> R >> C;
    map.resize(R, vector<char>(C));

    for (int y = 0; y < R; y++)
    {
        for (int x = 0; x < C; x++)
        {
            cin >> map[y][x];
        }
    }

    DFS(0, 0, 1); // 처음 0,0도 카운트 1로 들어간다
    cout << maxCnt << endl;

    return 0;
}