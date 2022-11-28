#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
using namespace std;

long long Gcd(long long a, long long b)
{
    // 최소공배수 구하기
    if (a < b)
    {
        long long tmp = a;
        a = b;
        b = tmp;
    }

    long long tmp;
    while (b != 0)
    {
        tmp = a % b;
        a = b;
        b = tmp;
    }

    return a;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    freopen("input.txt", "rt", stdin);
    long long a, b, gcd;
    cin >> a >> b;

    gcd = Gcd(a, b); // 최대공약수를 구한다

    cout << (a * b) / gcd; // 최소공배수는 두 수 곱한거에 / 최대공약수를 하면 구해진다
    return 0;
}
