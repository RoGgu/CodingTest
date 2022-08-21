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
    int X;
    cin >> X;

    // 절반으로 나눠서 더해진 나머지 개 수를 구한다.
    // 이진수 표현에서 1의 개수

    int ans = 0;
    while (X > 0)
    {
        if (X % 2 == 1)
        {
            ans++;
        }
        X /= 2;
    }

    cout << ans;
    return 0;
}
