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
    int E, S, M, year = 1;
    cin >> E >> S >> M;

    while (true)
    {
        if ((year - E) % 15 == 0 && (year - S) % 28 == 0 && (year - M) % 19 == 0) // 세가지 조건의 배수가 되는 수가 정답 년도이다.
            break;
        else
            ++year;
    }

    cout << year;
    return 0;
}