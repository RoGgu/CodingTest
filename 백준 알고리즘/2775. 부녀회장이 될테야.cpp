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


int Func(int k, int n)
{
    if (n == 1) // 1호에 사는 사람은 층 수 구분없이 다 1명이다.
        return 1;
    else if (k == 0)
    {
        // 0층이면 호 만큼의 사람이 산다.
        return n;
    }
    else // k층 n호의 사람 수는 k층 n-1호 사람 수 + k-1층 n호 사람 수만큼이다.
        return Func(k, n - 1) + Func(k - 1, n);

}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    freopen("input.txt", "rt", stdin);
    int T, k, n;
    cin >> T;
    for (int i = 0; i < T; i++)
    {
        cin >> k >> n;
        cout << Func(k, n) << "\n";

    }

    return 0;
}