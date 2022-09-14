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
    int R, C;
    int minN = 1001; // 가장 큰 수가 1000 범위 안
    pair<int, int> block;
    vector<vector<int>> graph(1001, vector<int>(1001));
    string s;

    //배열 입력
    cin >> R >> C;
    for (int y = 0; y < R; y++)
    {
        for (int x = 0; x < C; x++)
        {
            cin >> graph[y][x];

            // 행,열 모두 짝수 일 경우
            // 체스판 모양으로 배열을 표시할 때 시작지점, 도착지점을 검은색 칸 이라고 가정하면
            // 흰색 칸 하나만 빼면 모든 칸을 다 갈 수 있다.
            // 따라서 가장 큰 합을 위해서 가장 작은 흰색 칸 하나를 뺴기위해 가장 작은 흰색 칸 하나를 찾아 세팅한다.
            if (graph[y][x] < minN && (y + x) % 2 == 1)
            {
                block.first = y;
                block.second = x;
                minN = graph[y][x];
            }
        }
    }

    if (R % 2 == 1) // 행이 홀 수일 경우 모든 칸을 다 지날 수 있다.
    {
        for (int y = 0; y < R; y++)
        {
            for (int x = 0; x < C - 1; x++)
            {
                if (y % 2 == 0)
                    s.append("R");
                else
                    s.append("L");
            }
            if (y < R - 1)
                s.append("D");
        }

    }
    else if (C % 2 == 1) // 열이 홀 수일 경우에도 모든 칸을 다 지날 수 있다.
    {
        for (int x = 0; x < C; x++)
        {
            for (int y = 0; y < R - 1; y++)
            {
                if (x % 2 == 0)
                    s.append("D");
                else
                    s.append("U");
            }
            if (x < C - 1)
                s.append("R");
        }
    }
    else // 행,열 모두 짝 수 일 경우 가장 작은 흰색 칸을 빼고 모든 칸을 지나도록 한다.
    {
        // 2줄씩 지나야 하기 떄문에 2줄씩 끊기 위해 흰색 칸이 있는 2줄의 시작 행 값을 세팅한다.
        int blockR;
        if (block.first % 2 == 0)
            blockR = block.first;
        else
            blockR = block.first - 1;

        // 흰색칸이 속해있는 2줄 묶음 위에까지는 2줄 씩 좌, 우로 왔다갔다 하면서 모든칸을 지난다.
        for (int y = 0; y < blockR; y++)
        {
            for (int x = 0; x < C - 1; x++)
            {
                if (y % 2 == 0)
                    s.append("R");
                else
                    s.append("L");
            }
            if (y < blockR)
                s.append("D");
        }

        // 흰색 칸 속해있는 2줄에서 흰색 칸 열 만나기 전까지 움직임
        for (int x = 0; x < block.second; x++)
        {
            if (x % 2 == 0)
                s.append("DR");
            else
                s.append("UR");
        }

        // 흰색 칸 속해있는 2줄에서 흰색 칸 열 만난 후 해당 2줄 오른쪽 아래까지 끝까지 이동
        for (int x = block.second; x < C - 1; x++)
        {
            if (x % 2 == 0)
                s.append("RD");
            else
                s.append("RU");
        }
        // 지금까지에 이동 후 도착이면 내려갈 필요 없이 끝내고 아직 남아 있다면 한 칸 내려가야 한다.
        if (blockR + 2 != R)
            s.append("D");

        // 이후로 2줄 씩 좌, 우로 모든칸을 이동한다.
        for (int y = blockR + 2; y < R; y++)
        {
            for (int x = 0; x < C - 1; x++)
            {
                if (y % 2 == 0)
                    s.append("L");
                else
                    s.append("R");
            }
            if (y < R - 1)
                s.append("D");
        }
    }

    // 정답 경로 출력
    cout << s;
    return 0;
}


