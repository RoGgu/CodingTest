#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<queue>
#include<vector>
#include<algorithm>
#include<math.h>
#include<map>
#include<set>

using namespace std;

int Gcd(int x, int y) // 유클리드 호제법으로 최대 공약수 구한다
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
    freopen("input.txt", "rt", stdin); // input.txt 파일 읽기
    int x, y;
    cin >> x >> y;
    int gcd = Gcd(x, y);
    int lcm = x * y / gcd; // 두 수의 곱 / 최대 공약수가 최소 공배수가 된다.
    cout << gcd << "\n" << lcm;
    return 0;
}

