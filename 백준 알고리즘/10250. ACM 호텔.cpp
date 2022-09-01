#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<string>
#include<vector>
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
    int T, H, W, N;
    cin >> T;

    for (int i = 0; i < T; i++)
    {
        cin >> H >> W >> N;
        int cnt = 0;
        int res = 0;
        vector<vector<int>> hotel(H + 1, vector<int>(W + 1, 0));


        // 가로가 제일 가까운 방을 구해야 하니 높이 세로로 먼저 돌면서 빈 방 찾는다.
        // 세로가 방이 다 찼으면 그다음 가로 방의 세로 방을 다 찾아본다
        while (res == 0)
        {
            bool isFind = false;
            for (int w = 1; w <= W; w++)

            {
                for (int h = 1; h <= H; h++)
                {
                    if (hotel[h][w] == 0)  // 0 이면 아직 빈방
                    {
                        isFind = true;
                        hotel[h][w] = 1;
                        cnt++; // 손님 수 체크 증가

                        if (cnt == N) // N번쨰 손님이면 방 번호 계산
                            res = h * 100 + w;
                    }
                }
                if (isFind)
                    break;
            }
        }

        cout << res << "\n";
    }

    return 0;
}
