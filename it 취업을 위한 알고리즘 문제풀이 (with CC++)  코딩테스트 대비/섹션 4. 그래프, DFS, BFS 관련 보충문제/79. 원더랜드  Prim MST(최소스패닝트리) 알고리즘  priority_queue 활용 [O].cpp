#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>	// cin,cout말고 이제 c에서 제공하는 sanf, printf 사용 - 속도가 조금 더 빠름
#include<vector>
#include<queue>
#include<algorithm>

using namespace std;

// Prim MST(최소패닝트리) 활용
// priority_queue를 활용한다.
// 임의에 한개 큐에 담고 시작
// 그 노드에 연결된 노드와 간선을 (노드, 간선) 이렇게 담고
// top() 제일 가중치 값이 작은걸 빼내고
// 그 노드랑 연결된 노드와 간선들을 넣는다
// 그렇게 최소 가중치로 노드들은 연결한다.

struct Node // 가중치 그래프 저장을 위한 구조체
{
	int num; // 노드 번호
	int g; // 가중치 값

	Node(int a, int c)
	{
		num = a;
		g = c;
	}

	bool operator<(const Node& st) const // priority_queue 최소 힙으로 구서하게 만듬 
	{
		return g > st.g;
	}
};


int main()
{
	//freopen("input.txt", "rt", stdin); // input.txt 파일 읽기
	int n, m, i, a, b, c, cnt = 0, sum = 0;
	priority_queue<Node> q; // 최소 힙 큐
	scanf("%d %d", &n, &m);
	vector<int> v(n + 1); // 노드 넣었는지 체크 배열
	vector<vector<int>> map(n + 1, vector<int>(n + 1)); // 가중치 맵

	for (i = 1; i <= m; i++)
	{
		scanf("%d %d %d", &a, &b, &c);
		map[a][b] = c; // 무방향 그래프로 만듬
		map[b][a] = c;
	}

	q.push(Node(1, 0)); // 출발지점 1번 지점 넣어줌

	while (!q.empty() || cnt != n) // 더 이상 넣을 간선이 없거나, 노드 연결 다 될떄까지
	{
		Node tmp = q.top(); // 맨위 최소 가중치 노드 하나 뺸다
		q.pop();

		if (v[tmp.num] == 0) // 그 노드가 이미 연결되어있는지 확인
		{
			v[tmp.num] = 1; // 연결 되었다고 배열에 넣어줌
			sum += tmp.g; // 가중치 더함
			cnt++; // 노드 개수 체크
			for (i = 1; i <= n; i++)
			{
				if (map[tmp.num][i] > 0) // 그 노드랑 연결된 간선 q에 넣어줌
					q.push(Node(i, map[tmp.num][i]));
			}
		}
	}

	printf("%d", sum);
	return 0;
}
