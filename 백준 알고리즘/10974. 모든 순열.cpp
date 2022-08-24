#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<string>
#include<vector>
#include<queue>
#include<algorithm>
#include<cmath>
#include<map>
using namespace std;

int n;

void DFS(vector<int>& ch, vector<int>& v)
{
    if (v.size() == n) // 현재 배열에 저장된 v 수가 n 개수 만큼 충족해지면 쌓인 순서대로 순열 출력
    {
        for (int i = 0; i < v.size(); i++)
        {
            cout << v[i];
        }
        cout << "\n";
        return;
    }
    else
    {
        for (int i = 1; i <= n; i++)
        {
            if (ch[i] == 0)
            {
                ch[i] = 1;
                v.push_back(i);
                DFS(ch, v);
                ch[i] = 0;
                v.pop_back();
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
    vector<int> v; // 순열 쌓는 배열
    vector<int> ch(n + 1, 0); // 현재 순열에 들어있는 수 체크

    DFS(ch, v);

    return 0;
}
