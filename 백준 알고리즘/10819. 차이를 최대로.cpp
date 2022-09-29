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

int n;
vector<int>v;
vector<int>ch; // 계산한 수 체크
int maxNum = -2147000000;

void DFS(int cnt, int prvNum, int sum)
{
    if (cnt == n)
    {
        // 숫자 전부 더 했으면 최댓값이랑 비교해서 세팅
        if (sum > maxNum)
            maxNum = sum;
        return;
    }
    else
    {
        // 전부 다 돌면서 숫자를 더하는 계산을 해본다
        for (int i = 0; i < n; i++)
        {
            if (ch[i] == 0)
            {
                ch[i] = 1;
                DFS(cnt + 1, v[i], sum + abs(prvNum - v[i]));
                ch[i] = 0;
            }
        }
    }
}


int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    freopen("input.txt", "rt", stdin);
    cin >> n;
    v.resize(n);
    ch.resize(n, 0);
    for (int i = 0; i < n; i++)
        cin >> v[i];

    for (int i = 0; i < n; i++)
    {
        // 처음 수 세팅 하면서 전부 계산해본다.
        ch[i] = 1;
        DFS(1, v[i], 0);
        ch[i] = 0;
    }
    cout << maxNum;

    return 0;
}