#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>	// cin,cout말고 이제 c에서 제공하는 sanf, printf 사용 - 속도가 조금 더 빠름
#include<vector>
#include<queue>
#include<algorithm>

using namespace std;

// 벨만-포드 알고리즘
// 음의 사이클이 없을 때 사용할 수 있는 알고리즘
// 음의 사이클 : 한 바퀴를 반복적으로 돌때 값이 계속 작아지는거

// 노드 간선수를 기준으로 간선 몇개를 써서 갈 수 있는지에 따라서 매 간선 하나씩 증가해서 배열로 최소값을 기록해둔다.
// 노드 하나씩 증가해서 쓸때마다 새로 갱신 만약 갱신되는 값이 기존 값보다 크면 기존값 그대로 쓴다.
// 간선 가중치 더할때 기존 간선 가중치 최소값 + 이동하는데 드는 값
// - ex)? 2까지 간 가중치값이 12고 2->3까지가는데 5면 3의 값은 17

// 노드 간선 수는 노드에 개수 -1 즉 -1까지만 해서 최소값들을 갱신한다.
// 근데 마지막에 노드 수 까지 한번 다시 돌려보는데 기존에 최소값 배열보다 작아지면 음의 사이클이 있는거다.

struct Edge
{
	int s;
	int e;
	int val;

	Edge(int a, int b, int c)
	{
		s = a;
		e = b;
		val = c;
	}
};

int main()
{
	freopen("input.txt", "rt", stdin); // input.txt 파일 읽기
	int n, m, i, j, a, b, c, s, e;
	int dist[101] = { 0 };
	scanf("%d %d", &n, &m);
	vector<Edge> Ed; // 간선 정보들 배열로 저장, 2차원 배열로 안하는건 간선 한번씩 다 돌면서 계산하기 떄문에 그냥 배열

	for (i = 1; i <= m; i++) // 가중치 맵 생성
	{
		scanf("%d %d %d", &a, &b, &c);
		Ed.push_back(Edge(a, b, c));
	}
	for (i = 1; i <= n; i++)
		dist[i] = 2147000000;

	scanf("%d %d", &s, &e); // 시작 지점 끝지점 기록
	dist[s] = 0; // 시작지점은 0

	for (i = 1; i < n; i++) // 노드 수 -1까지 돌린다.
	{
		for (j = 0; j < Ed.size(); j++)
		{
			// 시작 지점 간선이 무한대 설정인 2147000000이면 현재 간선 개수로는 갈 수 없는곳, 
			// 기존 간선으로 갈 수 있게 세팅된 가중치보다 적게있어야지 세팅한다.
			if (dist[Ed[j].s] != 2147000000 && dist[Ed[j].s] + Ed[j].val < dist[Ed[j].e])
			{
				dist[Ed[j].e] = dist[Ed[j].s] + Ed[j].val;
			}
		}
	}

	for (i = 1; i < n; i++) // 노드 수 -1까지 돌린다.
	{
		for (j = 0; j < Ed.size(); j++)
		{
			// n-1 간선가지 최소 값 가중치 다 세팅되어있는데
			// n까지 돌렸을떄 값이 작아지는 가중치 노드가 생기면 음의 사이클이 있는 경우다.
			if (dist[Ed[j].s] != 2147000000 && dist[Ed[j].s] + Ed[j].val < dist[Ed[j].e])
			{
				printf("-1");
				exit(0);
			}
		}
	}

	// 음의 사이클 없어서 프로그램 살아있으면 이제 도착지점 간순 가중치값 표시
	printf("%d", dist[e]);
	return 0;
}
