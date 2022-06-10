#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<string.h>
#include<vector>
#include<algorithm>
using namespace std;

int n, m;
vector<int> v;

void DFS(int num, int c)
{
    if (c == m) // m 개 세팅되면 찾으면 출력
    {
        for (int i = 0; i < v.size(); i++)
        {
            cout << v[i] << " ";
        }
        cout << "\n";
    }
    else
    {
        for (int i = 1; i <= n; i++)
        {
            if (i > num) // 증가되야 해서 더 클때만 DFS 탐색
            {
                v.push_back(i);
                DFS(i, c + 1);
                v.pop_back();
            }
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    freopen("input.txt", "rt", stdin);
    cin >> n >> m;
    DFS(0, 0);

    return 0;
}