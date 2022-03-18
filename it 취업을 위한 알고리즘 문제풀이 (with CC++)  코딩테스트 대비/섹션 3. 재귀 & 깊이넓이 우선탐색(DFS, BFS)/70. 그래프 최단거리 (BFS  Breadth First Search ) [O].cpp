#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>	// cin,cout말고 이제 c에서 제공하는 sanf, printf 사용 - 속도가 조금 더 빠름
#include<vector>
#include<queue>
#include<algorithm>

using namespace std;

int main()
{
	//freopen("input.txt", "rt", stdin); // input.txt 파일 읽기
	int n, m, i, a, b, tmp;
	int ch[10] = { 0 };
	scanf("%d %d", &n, &m);

	vector<vector<int>> map(n + 1);
	vector<int> dis(n + 1, 0); // 정점 가는데 거린 간선 수
	queue<int> q;

	for (i = 0; i < m; i++)
	{
		scanf("%d %d", &a, &b);
		map[a].push_back(b);
	}

	q.push(1);
	ch[1] = 1;

	while (q.empty() == false)
	{
		tmp = q.front();
		q.pop();

		for (i = 0; i < map[tmp].size(); i++)
		{
			if (ch[map[tmp][i]] == 0)
			{
				ch[map[tmp][i]] = 1;
				q.push(map[tmp][i]);

				dis[map[tmp][i]] = dis[tmp] + 1; // 자기 연결된 정점까지의 간선 개 수 + 1
			}
		}
	}

	for (i = 2; i <= n; i++)
		printf("%d : %d\n", i, dis[i]);

	return 0;
}
