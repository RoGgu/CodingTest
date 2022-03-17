#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>	// cin,cout말고 이제 c에서 제공하는 sanf, printf 사용 - 속도가 조금 더 빠름
#include<vector>
#include<algorithm>

using namespace std;

// 넓이 우선 탐색(BFS)
// 레벨탐색 - 레벨이 먼저 낮은것부터터 다 탐색하고 다음 레벨 탐색
// 큐 자료구조 사용 (선입선출)
// - 먼저 들어간게 먼저 나오는 구조
// 완전 이진트리의 간선 개 수는 노드의 개수 -1

// 노드 7개인 이진트리를  BFS로
// 직접 큐 구현해서 풀어보자
// 무방향

int Q[100], front = -1, back = -1, ch[10];
vector<int> map[10];

int main()
{
	//freopen("input.txt", "rt", stdin); // input.txt 파일 읽기
	int i, a, b, x;
	for (i = 1; i <= 6; i++)
	{
		scanf("%d %d", &a, &b);
		map[a].push_back(b);
		map[b].push_back(a); // 무방향이라서 서로 갈 수 있다.
	}

	Q[++back] = 1; // 1번 노드부터 도니까 넣어준다
	ch[1] = 1;
	while (front < back) // front가 더 작아야 데이터가 남아있다는 뜻, 같아지면 비어진 순간
	{
		x = Q[++front];
		printf("%d ", x);

		for (i = 0; i < map[x].size(); i++)
		{
			if (ch[map[x][i]] == 0) // 이미 돈 건지 체크
			{
				ch[map[x][i]] = 1;
				Q[++back] = map[x][i]; // 안 돈거니까 Q에 넣어준다
			}
		}
	}

	return 0;
}
