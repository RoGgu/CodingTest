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


bool Check(int h, int m, int s)
{
    // 시, 분, 초에 3들어가 있는지 확인
    if (h % 10 == 3 || m / 10 == 3 || m % 10 == 3 || s / 10 == 3 || s % 10 == 3)
        return true;
    else
        return false;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    freopen("input.txt", "rt", stdin);
    int n, res = 0;
    cin >> n;

    for (int i = 0; i <= n; i++)
    {
        for (int j = 0; j < 60; j++)
        {
            for (int k = 0; k < 60; k++)
            {
                // 시, 분, 초에 3 들어가 있으면 카운트 증가
                if (Check(i, j, k))
                    res++;
            }
        }
    }

    cout << res;
    return 0;
}