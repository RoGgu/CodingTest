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
    int H, M;
    cin >> H >> M;

    if (M >= 45)
    {
        M -= 45;
    }
    else
    {
        // 분이 모자랄 경우 시에서 1 빼준다
        // 시가 0~24이여야 해서 24로 나눠준다.
        H = (H + 23) % 24;
        M += 15;
    }

    cout << H << " " << M;
    return 0;
}
