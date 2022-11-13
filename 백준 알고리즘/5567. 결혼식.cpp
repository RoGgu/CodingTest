#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<vector>
#include<queue>

using namespace std;

int n, m;
int visited[501];
vector<vector<int>> graph(501);
int cnt = 0;

void Bfs()
{
    queue<int> q;
    q.push(1);
    visited[1] = 1; // 1인 자신이랑 친구인 애부터 찾는다

    while (!q.empty())
    {
        int num = q.front();
        q.pop();

        for (int i = 0; i < graph[num].size(); i++)
        {
            int next = graph[num][i]; // 연결된 친구 정보
            if (visited[next] || visited[num] >= 3) // 이미 방문 초대했거나, 친구의 친구가 아닌 3다리 걸쳐 아는애면 패스
                continue;

            q.push(next);
            visited[next] = visited[num] + 1;
            cnt++;
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    freopen("input.txt", "rt", stdin);
    cin >> n >> m;
    for (int i = 0; i < m; i++)
    {
        int u, v;
        cin >> u >> v;
        // 무방향 그래프
        graph[u].push_back(v);
        graph[v].push_back(u);
    }

    Bfs();
    cout << cnt;
    return 0;
}
