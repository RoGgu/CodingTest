#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>	// cin,cout말고 이제 c에서 제공하는 sanf, printf 사용 - 속도가 조금 더 빠름
#include<vector>
#include<algorithm>

using namespace std;

// 인접 행렬

// 정점 : 노드
// 간선 : 연결된 선 

// 3가지 버전이 있다
// 무 방향 : 방향이 없어서 그냥 연결되있는지 보는 경우
// 방향 : 어떤 방향으로 간선이 연결되는지 체크
// 가중치 : 방향이 있고 그 간선의 가중치 값이 있다.

// 인접행렬은 이중배열로 만들어서 관리
// 방향이나 가중치면, 행이 시작 방향, 열이 도착 정보


int main()
{
	freopen("input.txt", "rt", stdin); // input.txt 파일 읽기
	int n, m, i, j, s, e, g;
	scanf("%d %d", &n, &m);

	vector<vector<int>> map(n + 1, vector<int>(n + 1, 0)); // 행렬 만들어준다

	for (i = 1; i <= m; i++)
	{
		scanf("%d %d %d", &s, &e, &g); // 간선 정보 세팅
		// s: 간석 시작, e :간선 도착, g : 간선 가중치
		map[s][e] = g; // 이중배열로 만들어서 시작 행, 도착 열에 가중치 값 너어줌

	}

	for (i = 1; i <= n; i++)
	{
		for (j = 0; j < n; j++)
		{
			printf("%d ", map[i][j]);
		}
		printf("\n");
	}

	return 0;
}
