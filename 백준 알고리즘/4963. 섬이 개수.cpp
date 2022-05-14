#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<queue>
#include<vector>
#include<algorithm>
#include<math.h>


using namespace std;

int main()
{
    freopen("input.txt", "rt", stdin); // input.txt 파일 읽기
    int w, h, cnt;
    vector<vector<int>> map;
    queue<pair<int, int>> q;
    int dy[] = { -1, -1, -1,  0, 0 ,  1, 1, 1 };
    int dx[] = { -1,  0,  1, -1, 1 , -1, 0, 1 };

    while (true)
    {
        cnt = 0;
        cin >> w >> h;

        if (w == 0 && h == 0)
            break;
        map.clear();
        map.resize(h, vector<int>(w));
        for (int y = 0; y < h; y++)
        {
            for (int x = 0; x < w; x++)
            {
                cin >> map[y][x];
            }
        }

        for (int y = 0; y < h; y++)
        {
            for (int x = 0; x < w; x++)
            {
                // 아직 발견되지 않은 섬 발견하면 카운트하고 연결된 섬 다 0처리
                if (map[y][x] == 1)
                {
                    cnt++;
                    map[y][x] = 0;
                    q.push(make_pair(y, x));

                    // 섬 발견헀다면 연결되어있는 섬 다 0으로 처리
                    while (q.empty() == false)
                    {
                        int posY = q.front().first;
                        int posX = q.front().second;
                        q.pop();

                        for (int i = 0; i < 8; i++)
                        {
                            int ny = posY + dy[i];
                            int nx = posX + dx[i];

                            if (ny < 0 || ny >= h || nx < 0 || nx >= w)
                                continue;

                            if (map[ny][nx] == 1)
                            {
                                map[ny][nx] = 0;
                                q.push(make_pair(ny, nx));
                            }

                        }

                    }
                }
            }
        }

        cout << cnt << endl; // 현재 테스트 결과 출력
    }

    return 0;
}

