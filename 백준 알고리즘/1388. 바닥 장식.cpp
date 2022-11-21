#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<vector>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    freopen("input.txt", "rt", stdin);
    int h, w, cnt = 0;
    cin >> h >> w;
    vector<vector<char>> graph(h, vector<char>(w));
    vector<vector<int>> ch(h, vector<int>(w, 0)); // 이미 나무 판자 체크되어있는지 확인

    for (int i = 0; i < h; i++)
    {
        for (int j = 0; j < w; j++)
        {
            cin >> graph[i][j];
        }
    }

    for (int i = 0; i < h; i++)
    {
        for (int j = 0; j < w; j++)
        {
            if (ch[i][j] == 0)
            {
                ch[i][j] = 1;
                cnt++;

                if (graph[i][j] == '-') // 가로일 경우 그 옆에 가로로 이어지는 부분까지 전부 체크
                {
                    for (int k = j + 1; k < w; k++)
                    {
                        if (graph[i][k] != '-')
                            break;
                        else
                            ch[i][k] = 1;
                    }
                }
                else if (graph[i][j] == '|') // 세로일 경우 그 밑에 세로로 이어지는 부분까지 전부 체크
                {
                    for (int k = i + 1; k < h; k++)
                    {
                        if (graph[k][j] != '|')
                            break;
                        else
                            ch[k][j] = 1;
                    }
                }
            }
        }
    }

    cout << cnt;
    return 0;
}
