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
    int n, x = 1, y = 1;
    string plans;
    cin >> n;
    cin.ignore(); // 버퍼 비우기 
    getline(cin, plans);

    // 상하좌우 이동 설정 값
    int dy[4] = { -1, 1, 0 , 0 };
    int dx[4] = { 0, 0, -1 , 1 };
    char moveTypes[4] = { 'U', 'D', 'L', 'R' };

    for (int i = 0; i < plans.size(); i++)
    {
        // 예상 이동 방향 세팅
        int ny = -1;
        int nx = -1;

        for (int j = 0; j < 4; j++)
        {
            // getline으로 받아서 plans안에 공백 문자도 있어서 이동방향 체크 한다.
            if (plans[i] == moveTypes[j])
            {
                ny = y + dy[j];
                nx = x + dx[j];
                break;
            }
        }

        // 이동 가능한 범위인 경우 이동
        if (ny > 0 && ny <= n && nx > 0 && nx <= n)
        {
            y = ny;
            x = nx;
        }
    }

    cout << y << " " << x;
    return 0;
}