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

int Gcd(int a, int b)
{
    // 유클리드 호제법
    int c;
    while (b > 0)
    {
        c = a % b;
        a = b;
        b = c;
    }
    return a;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    freopen("input.txt", "rt", stdin);
    int num1 = 0, num2 = 0;
    bool bNum1 = true;
    string s;
    cin >> s;
    for (int i = 0; i < s.size(); i++)
    {
        if (s[i] == ':') // ':' 나오기 전까진 num1 수 그 뒤론 num2
        {
            bNum1 = false;
        }
        else
        {
            if (bNum1 == true)
            {
                num1 = (num1 * 10) + (s[i] - 48);
            }
            else
            {
                num2 = (num2 * 10) + (s[i] - 48);
            }
        }
    }

    int gcd = Gcd(num1, num2); // 최대 공약수를 먼저 구한다.
    cout << num1 / gcd << ":" << num2 / gcd; // 최대 공약수로 둘다 나눠줘서 최대 수를 출력한다.
    return 0;
}
