#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<string>
#include<vector>

using namespace std;

int num1[10001];
int num2[10001];
vector<int> v;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    freopen("input.txt", "rt", stdin);
    string a = "", b = "", tmp = "";
    int c = 0;
    cin >> a >> b;

    if (a.size() < b.size())
    {
        tmp = a;
        a = b;
        b = tmp;
    }

    // 1번 인덱스부터 숫자 세팅
    for (int i = 0; i < a.size(); i++)
    {
        num1[i + 1] = a[i] - '0';
    }
    for (int i = 0; i < b.size(); i++) {
        num2[i + 1 + a.size() - b.size()] = b[i] - '0';
    }

    for (int i = a.size(); i > 0; i--)
    {
        c = num1[i] + num2[i];
        if (c >= 10) // 같은 자리수에 합이 10을 넘을경우 다음 자리 수 1 증가
        {
            num1[i - 1]++;
            c -= 10;
        }

        v.push_back(c);
    }

    if (num1[0] != 0)// num1[0] 가 0이 아니면 마지막에 10이 넘어서 1 추가
    {
        v.push_back(1);
    }

    for (int i = v.size() - 1; i >= 0; i--)
    {
        // 0번부터 1의 자리라 반대로 출력
        cout << v[i];
    }
    return 0;
}
