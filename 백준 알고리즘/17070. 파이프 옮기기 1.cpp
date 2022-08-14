#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<queue>
#include<vector>
#include<algorithm>
#include<math.h>
#include<map>
#include<set>

using namespace std;


struct Info
{
    int x;
    int y;
    int d; // 파이브 놓여져 있는 방향 0,1,2 각각 가로,대각선,세로
};

int n, res;
int graph[17][17];
// 가로 세로 대각선 별 위치 증가 값
int dx[3] = { 1, 1, 0 };
int dy[3] = { 0, 1, 1 };
queue<Info> q;

void Move(int x, int y, int i)
{
    int nd = i; // 파이프 다음 이동 방향
    int nx = x + dx[i];
    int ny = y + dy[i];

    if (graph[ny][nx] == 0 && ny > 0 && ny <= n && nx > 0 && nx <= n)
    {
        if (nd == 1) // 대각선 이동일 경우 위 아래 추가로 확인 해야한다.
        {
            if (graph[ny - 1][nx] == 1 || graph[ny][nx - 1] == 1)
                return;
        }
        q.push({ nx,ny,nd });
    }

}



int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    freopen("input.txt", "rt", stdin); // input.txt 파일 읽기
    cin >> n;
    for (int y = 1; y <= n; y++)
    {
        for (int x = 1; x <= n; x++)
        {
            cin >> graph[y][x];
        }
    }

    q.push({ 2,1,0 });

    while (!q.empty())
    {
        int x = q.front().x;
        int y = q.front().y;
        int d = q.front().d;
        q.pop();

        if (x == n && y == n)
        {
            res++;
            continue;
        }

        switch (d)
        {
        case 0:
            Move(x, y, 0); // 가로 이동
            Move(x, y, 1); // 대각선 이동
            break;
        case 1:
            Move(x, y, 0); // 가로 이동
            Move(x, y, 1); // 대각선 이동
            Move(x, y, 2); // 세로 이동
            break;
        case 2:
            Move(x, y, 1); // 대각선 이동
            Move(x, y, 2); // 세로 이동
            break;
        }
    }

    cout << res;
    return 0;
}

