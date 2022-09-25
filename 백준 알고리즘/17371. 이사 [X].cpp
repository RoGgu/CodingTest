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

pair<int, int> graph[1001];

int Distance(int ax, int ay, int bx, int by)
{
    return (bx - ax) * (bx - ax) + (by - ay) * (by - ay);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    freopen("input.txt", "rt", stdin);
    int n, idx;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        // 편의시설 좌표 설정
        cin >> graph[i].first;
        cin >> graph[i].second;
    }

    int  minDistance = 2147000000;

    for (int i = 0; i < n; i++)
    {
        // 편의시설 하나를 기점으로 현재 기점기준 가장 먼 편의시설 을 찾는다
        int dis = 0;
        for (int j = 0; j < n; j++)
        {
            if (i == j)
                continue;

            dis = max(dis, Distance(graph[i].first, graph[i].second, graph[j].first, graph[j].second));
        }

        // 편의시설간의 최대 차이가 가작 적은 기점을 세팅
        if (dis < minDistance)
        {
            minDistance = dis;
            idx = i;
        }
    }

    // 편의시설 간의 먼 거리가 최소로 작은 편의시설 위치가 새로 집을 지을 좌표이다.
    cout << graph[idx].first << " " << graph[idx].second;
    return 0;
}