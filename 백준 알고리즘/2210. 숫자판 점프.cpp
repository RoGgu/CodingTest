#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
using namespace std;

int map[5][5];
int res = 0;
int dy[] = { 0,0,-1,1 };
int dx[] = { -1,1,0,0 };
bool visit[1000000]; // 이미 있는 숫자인지 체크 
vector<int> v;

void Dfs(int y, int x, int num, int cnt)
{
    if (cnt == 6)
    {
        // 6개 숫자 완성됬을때 중복된적 없으면 카운트 증가
        if (visit[num] == false)
        {
            visit[num] = true;
            res++;
        }
        return;
    }

    for (int i = 0; i < 4; i++)
    {
        // 상하좌우 체크
        int ny = y + dy[i];
        int nx = x + dx[i];

        if (ny < 0 || nx < 0 || ny >= 5 || nx >= 5)
            continue;

        Dfs(ny, nx, num * 10 + map[ny][nx], cnt + 1);
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    freopen("input.txt", "rt", stdin);

    for (int i = 0; i < 5; i++)
    {
        for (int j = 0; j < 5; j++)
        {
            cin >> map[i][j];
        }
    }

    // 모든 좌표 DFS로 탐색
    for (int i = 0; i < 5; i++)
    {
        for (int j = 0; j < 5; j++)
        {
            Dfs(i, j, 0, 0);
        }
    }

    cout << res;
    return 0;
}
