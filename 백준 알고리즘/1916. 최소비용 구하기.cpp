#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<queue>
#include<vector>
#include<algorithm>
#include<math.h>
#include<map>
#include<set>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    freopen("input.txt", "rt", stdin); // input.txt 파일 읽기
    int n, m, s, e, g;
    cin >> n >> m;
    vector<vector<pair<int, int>>> vec(n + 1); // 시작 지점 도착지점 비용세팅, 시작 도착 지점이 여러 개 일 수도 있다.
    vector<int> dist(n + 1, 2147000000); // 시작 지점으로 부터 도착 지점별 다익으로 최소 비용 세팅
    for (int i = 0; i < m; i++)
    {
        cin >> s >> e >> g;
        vec[s].push_back({ e,g });
    }
    cin >> s >> e;
    dist[s] = 0; // 시작지점 비용 0

    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq; // 우선순위 큐 오름차순으로 설정
    pq.push({ s, dist[s] });

    while (!pq.empty())
    {
        int cur = pq.top().first;
        int dis = pq.top().second;
        pq.pop();

        if (dist[cur] < dis) // 꺼낸 비용이 이미 세팅된 최소 비용보다 크면 넘긴다
            continue;

        for (int i = 0; i < vec[cur].size(); i++)
        {
            int next = vec[cur][i].first;
            int nDis = dis + vec[cur][i].second;// 현재까지 온 비용 + next로 가는 비용이 총 시작 지점에서 next까지 가는 총 비용

            if (nDis < dist[next]) // 이미 세티된 최소비용 보다 더 적은 비용으로 갈 수 있을 때 값 바꾸고 검사에 추가
            {
                dist[next] = nDis;
                pq.push({ next, nDis });
            }
        }
    }

    cout << dist[e];
    return 0;
}

