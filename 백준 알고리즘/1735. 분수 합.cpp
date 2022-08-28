#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<string>
#include<vector>
#include<queue>
#include<algorithm>
#include<cmath>
#include<map>
using namespace std;


int gcd(int x, int y)
{
    while (y != 0)
    {
        int r = x % y;
        x = y;
        y = r;
    }
    return x;
}


int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    freopen("input.txt", "rt", stdin);
    int n1, d1, n2, d2;
    cin >> n1 >> d1 >> n2 >> d2;
    int n = n1 * d2 + n2 * d1;
    int d = d1 * d2;
    int g = gcd(n, d); // 두 분수 더해서 구해진 분자 분모의 정수의 최대 공약수를 유클리드 호제법 사용해서 구한다.
    cout << n / g << " " << d / g; // 각각 분자 분모의 최대 공약수로 나눠준 값이 정답
    return 0;
}
