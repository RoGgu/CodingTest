#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<string.h>
#include<vector>
#include<queue>
#include<algorithm>
using namespace std;

// 다익스트라 알고리즘 활용해서 풀이

struct Edge
{
    int vex; // vex 정점까지 가는
    int dis; // 비용
    Edge(int v, int d)
    {
        vex = v;
        dis = d;
    }
    bool operator<(const Edge& b)const
    {
        return dis > b.dis;
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    freopen("input.txt", "rt", stdin);
    int V, E, K;
    cin >> V >> E >> K;
    priority_queue<Edge> pq;
    vector<pair<int, int>> graph[20001];
    vector<int> dist(V + 1, 2147000000);
    for (int i = 1; i <= E; ++i)
    {
        int u, v, w;
        cin >> u >> v >> w;
        graph[u].push_back(make_pair(v, w));
    }

    dist[K] = 0; // 시작지점이라서 시작 지점까지에 비용은 0이다, 
    pq.push(Edge(K, 0));

    while (!pq.empty())
    {
        int now = pq.top().vex;
        int cost = pq.top().dis;
        pq.pop();

        if (cost > dist[now])  // 기존에 이미 now로 온 비용이 더 작은게 있으면 계산 할 필요 X
            continue;

        for (int i = 0; i < graph[now].size(); ++i)
        {
            int next = graph[now][i].first;
            int nextDis = cost + graph[now][i].second; // 현재 now 정점까지 온 비용 + next 정점 가는 비용
            if (nextDis < dist[next]) // 새로 갱신한 비용이 기존꺼보다 작으면 새로 갱신하고 push
            {
                dist[next] = nextDis;
                pq.push(Edge(next, nextDis));
            }
        }
    }

    for (int i = 1; i <= V; ++i)
    {
        if (dist[i] == 2147000000)
            cout << "INF" << "\n";
        else
            cout << dist[i] << "\n";
    }

    return 0;
}