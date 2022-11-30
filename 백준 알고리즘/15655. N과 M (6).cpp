#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
using namespace std;

int N, M;
vector<int> v;

void Dfs(int idx, vector<int>& path)
{
    if (path.size() == M) // M 조건 수 만족하면 현재 담겨져 있는 수 들 출력
    {
        for (int i = 0; i < path.size(); i++)
        {
            cout << path[i] << " ";
        }
        cout << endl;
    }
    else
    {
        for (int i = idx; i < N; i++)
        {
            path.push_back(v[i]);
            Dfs(i + 1, path); // 현재 넣은 index에 다음 수부터 체크
            path.pop_back();
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> N >> M;
    v.resize(N);

    for (int i = 0; i < N; i++)
    {
        cin >> v[i];
    }

    // 사전 순 출력하기 위해 오름차순 정렬
    sort(v.begin(), v.end());

    vector<int> path;
    Dfs(0, path);

    return 0;
}
