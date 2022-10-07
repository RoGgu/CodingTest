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


int N, M;
vector<int> res;

void DFS(int num, int cnt)
{
    if (cnt == M)
    {
        for (int i = 0; i < res.size(); i++)
        {
            cout << res[i] << " ";
        }
        cout << "\n";
    }
    else
    {
        for (int i = 1; i <= N; i++)
        {
            res.push_back(i);
            DFS(i, cnt + 1);
            res.pop_back();
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    freopen("input.txt", "rt", stdin);
    cin >> N >> M;
    DFS(1, 0);


    return 0;
}
