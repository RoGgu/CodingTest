#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<string>
#include<algorithm>

using namespace std;

int n, m;
string dp[102][102];

string StringNumAdd(string str1, string str2)
{
    // string 더하기 
    if (str1.length() > str2.length())
    {
        swap(str1, str2);
    }

    string tempStr = "";
    int difLength = str2.length() - str1.length();
    int carry = 0;

    for (int i = (str1.length() - 1); i >= 0; i--)
    {
        int sum = (str1[i] - '0') + (str2[i + difLength] - '0') + carry;
        tempStr.push_back(sum % 10 + '0');
        carry = sum / 10;
    }

    for (int i = (difLength - 1); i >= 0; i--)
    {
        int sum = (str2[i] - '0') + carry;
        tempStr.push_back(sum % 10 + '0');
        carry = sum / 10;
    }

    if (carry)
    {
        tempStr.push_back(carry + '0');
    }

    reverse(tempStr.begin(), tempStr.end()); // 1의자리가 0번 인덱스부터 있어서 뒤집어 줘야 한다

    return tempStr;
}

string Combination(int n, int m)
{
    // 파스칼의 삼각형 방식으로 답을 구한다
    // 메모제이션 방식으로 중간에 값 저장
    if (n == m || m == 0)
        return "1";

    if (dp[n][m] == "")
    {
        // 저장된 값이 없을 경우 파스칼의 삼각형 방식으로 값 구한다
        dp[n][m] = StringNumAdd(Combination(n - 1, m - 1), Combination(n - 1, m));
    }

    return dp[n][m];
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    freopen("input.txt", "rt", stdin);
    cin >> n >> m;

    string res = Combination(n, m);
    cout << res;
    return 0;
}
