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

int k;
vector<int> s;
vector<int> path; // 뽑은 숫자 정보들

void DFS(int idx, int cnt)
{
    if (cnt == 6) // 숫자 6개가 완성되면 출력한다
    {
        for (int i = 0; i < path.size(); i++)
            cout << path[i] << " ";
        cout << "\n";
    }
    else
    {
        for (int i = idx + 1; i < s.size(); i++)
        {
            path.push_back(s[i]);
            DFS(i, cnt + 1);
            path.pop_back();
        }
    }
}


int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    freopen("input.txt", "rt", stdin);

    while (true)
    {
        cin >> k;
        if (k == 0)
            break;

        s.resize(k);
        path.clear();
        for (int i = 0; i < k; i++)
            cin >> s[i];

        for (int i = 0; i < k; i++)
        {
            path.push_back(s[i]);
            DFS(i, 1);
            path.pop_back();
        }

        cout << "\n"; // 테스트 한 줄 끝나면 줄 바꿈
    }

    return 0;
}