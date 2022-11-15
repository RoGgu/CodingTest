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
    int res = 0;
    string pos;
    cin >> pos;

    // 나이트가 이동 가능한 8가지 경우 값
    int dy[8] = { -2, -2, 2, 2, -1, 1, -1, 1 };
    int dx[8] = { -1, 1, -1, 1, 2, 2, -2, -2 };

    int x, y;
    // 문자열 아스키 코드 값 int로 세팅
    y = pos[1] - 48; // 
    x = pos[0] - 'a' + 1;

    for (int i = 0; i < 8; i++)
    {
        // 예상 이동 위치
        int ny = y + dy[i];
        int nx = x + dx[i];

        // 이동 가능한 경우 개수 증가
        if (ny > 0 && ny <= 8 && nx > 0 && nx <= 8)
        {
            res++;
        }
    }

    cout << res;
    return 0;
}