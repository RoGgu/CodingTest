#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<string>
#include<vector>
#include<queue>
#include<algorithm>
#include<cmath>
#include<map>
using namespace std;


int Factorial(int n)
{
    if (n == 1 || n == 0)
        return 1;


    int res = 1;
    for (int i = n; i >= 1; i--)
    {
        res *= i;
    }

    return res;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    freopen("input.txt", "rt", stdin);
    int n, k, res = 0;
    cin >> n >> k;

    // 이항계수 공식 n! / ((n-k)! * k!) 를 팩토리얼 이용해서 풀이
    res = Factorial(n) / (Factorial(n - k) * Factorial(k));

    cout << res;
    return 0;
}
