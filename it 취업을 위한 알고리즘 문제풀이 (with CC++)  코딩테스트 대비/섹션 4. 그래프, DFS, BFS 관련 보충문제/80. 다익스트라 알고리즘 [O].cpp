#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>	// cin,cout말고 이제 c에서 제공하는 sanf, printf 사용 - 속도가 조금 더 빠름
#include<vector>
#include<queue>
#include<algorithm>

using namespace std;

// 다익스트라 알고리즘
// 간선 값이 양수일때만 통하는 알고리즘
// n만큼 일차원 배열값을 만들고 1 빼고는 전부 최대값을 넣는데 ex)2147000000
// - 1은 시작 지점이기때문에 가중치에 합이 0이다
// 한번 씩 돌면서 최소 가중치 값을 찾고 해당 가중치 값의 노드부터 다른 노드를 연결하면서 가중치 값을 계산해준다
// - 이떄 새로 매겨지는 가중치의 값이 기존에 가중치 값보다 클 경우는 기존 값을 유지한다.
// 매번 최소 가중치값을 찾아서 매기는걸 반복한다
// 이때 최대값이 그대로 있는 애는 갈 수가 없는애다.

// 매번 최대 가중치값을 for문돌면서 찾기엔 시간 낭비여서
// priority_queue를 활용해서 최소힙으로 바로 top()으로 구하도록 사용한다. 


struct Edge
{
	int num; // 정점 번호
	int dis; // 정점까지 가는 비용

	Edge(int n, int v)
	{
		num = n;
		dis = v;
	}

	bool operator<(const Edge& e) const // 최소힙으로 만들기 위해
	{
		return dis > e.dis;
	}
};

int main()
{
	//freopen("input.txt", "rt", stdin); // input.txt 파일 읽기
	int n, m, i, s, e, g, sum = 0;
	scanf("%d %d", &n, &m);
	vector<vector<int>> map(n + 1, vector<int>(n + 1));
	vector<int> dist(n + 1, 2147000000); // 현재 그 노드까지 가는 가중치 값 모음 - 처음엔 최대 값으로 설정
	priority_queue<Edge> q;

	for (i = 1; i <= m; i++) // 가중치 맵 생성
	{
		scanf("%d %d %d", &s, &e, &g);
		map[s][e] = g;
	}

	q.push(Edge(1, 0)); // 1번 정점부터 가니까 1번 넣어줌
	dist[1] = 0; // 1번 은 시작점이니까 비용은 0

	while (!q.empty())
	{
		Edge tmp = q.top(); // 맨위 가중치 제일 작은거 뺴줌
		q.pop();

		if (dist[tmp.num] < tmp.dis) // 이미 작은 값으로 세팅되어있으면 더 작아질 수 없어서 넘어감
			continue;
		for (i = 1; i <= n; i++)
		{
			if (map[tmp.num][i] > 0)
			{
				if (dist[i] > dist[tmp.num] + map[tmp.num][i]) // 가중치 값이 작을떄만 갈만한 길이라서 그때 세팅하고 넣어줌
				{
					dist[i] = dist[tmp.num] + map[tmp.num][i];
					q.push(Edge(i, dist[i]));
				}
			}
		}
	}

	for (i = 2; i <= n; i++)
	{
		if (dist[i] == 2147000000) // 최대 값 그대로면 갈 수 없는 노드
			printf("%d : impossible\n", i);
		else
			printf("%d : %d\n", i, dist[i]);
	}

	return 0;
}


// DFS 로 푼거

//int n;
//int minG = 2147000000;
//int ch[21];
//vector<vector<int>> map(21, vector<int>(21));
//
//void DFS(int v, int e, int sum)
//{
//	if (v == e)
//	{
//		if (sum < minG)
//			minG = sum;
//		return;
//	}
//	else
//	{
//		for (int i = 1; i <= n; i++)
//		{
//			if (map[v][i] > 0 && ch[i] == 0)
//			{
//				ch[i] = 1;
//				DFS(i, e, sum + map[v][i]);
//				ch[i] = 0;
//			}
//		}
//	}
//}
//
//
//int main()
//{
//	//freopen("input.txt", "rt", stdin); // input.txt 파일 읽기
//	int m, i, s, e, g, sum = 0;
//
//	scanf("%d %d", &n, &m);
//
//	for (i = 1; i <= m; i++)
//	{
//		scanf("%d %d %d", &s, &e, &g);
//		map[s][e] = g;
//	}
//
//	for (i = 2; i <= n; i++)
//	{
//		minG = 2147000000;
//		ch[1] = 1;
//		DFS(1, i, 0);
//
//		if (minG == 2147000000)
//			printf("%d : impossible\n", i);
//		else
//			printf("%d : %d\n", i, minG);
//	}
//	return 0;
//}
