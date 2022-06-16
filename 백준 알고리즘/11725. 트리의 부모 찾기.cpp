#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<string.h>
#include<vector>
#include<queue>
#include <unordered_map>
using namespace std;

int n;
vector<vector<int>> tree(n + 1);
vector<int> parent(n + 1, 0);

void SetParent(int num)
{
    for (int i = 0; i < tree[num].size(); i++) // 연결된거 보면서 부모 세팅
    {
        int nextNum = tree[num][i];
        if (parent[nextNum] == 0) // 이미 부모 세팅되어 있는건 다시 탐색할 필요 없다.
        {
            parent[nextNum] = num;
            SetParent(nextNum);
        }
    }
}


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    freopen("input.txt", "rt", stdin);

    cin >> n;
    tree.resize(n + 1);
    parent.resize(n + 1);

    for (int i = 0; i < n; i++) // 그래프 양방향 세팅
    {
        int a, b;
        cin >> a >> b;
        tree[a].push_back(b);
        tree[b].push_back(a);
    }

    parent[1] = 1; // 1에 부모는 자기 자신
    SetParent(1); // 1이랑 연결된거 부터 돌면서 부모 세팅

    for (int i = 2; i <= n; i++)
        cout << parent[i] << "\n";

    return 0;
}