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
    int A, B;
    cin >> A >> B;
    int rA = 0, rB = 0;

    while (A != 0)
    {
        rA = rA * 10 + A % 10;
        A = A / 10;
    }

    while (B != 0)
    {
        rB = rB * 10 + B % 10;
        B = B / 10;
    }

    if (rA > rB)
    {
        cout << rA;
    }
    else
        cout << rB;

    return 0;
}
