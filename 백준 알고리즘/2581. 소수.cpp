#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<string>
#include<vector>
#include<queue>
#include<algorithm>
#include<cmath>
using namespace std;


int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    freopen("input.txt", "rt", stdin);
    int M, N;
    int sum = 0, min = -1;
    cin >> M >> N;

    for (int i = M; i <= N; i++)
    {
        if (i == 1) // 1은 소수 아니여서 넘김
            continue;

        bool isSosu = true;

        for (int div = 2; div < i; div++)
        {
            if (i % div == 0)
            {
                isSosu = false;
                continue;
            }
        }

        if (isSosu)
        {
            if (min == -1)		//저장된 소수의 최솟값이 없을 때
                min = i;
            sum += i;
        }
    }

    if (min == -1)
        cout << -1 << '\n';
    else
        cout << sum << '\n' << min << '\n';

    return 0;
}
