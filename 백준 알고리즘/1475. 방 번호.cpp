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
    int n, tmp, res = 0;
    cin >> n;
    vector<int> ch(10, 0);

    while (n > 0)
    {
        tmp = n % 10;
        n = n / 10;

        if (tmp == 6 || tmp == 9)  // 6과 9는 서로 돌려 쓸 수 있어서 6으로 체크
        {
            tmp = 6;
            if (ch[tmp] >= res * 2)
            {
                res++;
            }
            ch[tmp]++;
        }
        else
        {
            if (ch[tmp] >= res)
            {
                res++;
            }
            ch[tmp]++;
        }
    }

    cout << res;
    return 0;
}
