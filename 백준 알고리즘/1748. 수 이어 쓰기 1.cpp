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
    int n, res = 0;
    cin >> n;

    // n 까지의 각 자리 수의 합을 구한다.
    // 1의 자리수는 n -10 +1,
    // 10의 자리수는 n - 100 + 1
    // 100의 자리수는 n - 1000 + 1
    // 이런식으로 공식을 통해서  n 까지의 각 자리 수의 합을 구한다.
    for (int i = 1; i <= n; i = i * 10)
    {
        res += n - i + 1;
    }

    cout << res;
    return 0;
}