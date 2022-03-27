#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>	// cin,cout말고 이제 c에서 제공하는 sanf, printf 사용 - 속도가 조금 더 빠름
#include<vector>
#include<queue>
#include<algorithm>

using namespace std;

// 크루스칼 알고리즘 사용
// 최소비용의 트리를 만들어낸다.

// 가중치 값으로 오름차순 정렬하고
// 차례대로 연결되어있는지 판단해서 연결 안 되어있다면 연결해주고 가중치 값 더해줌
// 연결된 간선 수가 노드 -1 개면 전부 연결 된거로 판단하고 종룔

struct ST // 가중치 그래프 저장을 위한 구조체
{
	int numA;
	int numB;
	int g;

	ST(int a, int b, int c)
	{
		numA = a;
		numB = b;
		g = c;
	}

	bool operator<(const ST& st) const // 구조체 비교는 g 가중치로 오름차순 정렬 한다
	{
		return g < st.g;
	}
};

int unf[30];

int Find(int v)
{
	if (v == unf[v])
		return v;
	else
		return unf[v] = Find(unf[v]);
}

bool Unf(int a, int b)
{
	a = Find(a);
	b = Find(b);
	if (a != b) // 새로 연결될 때만 가중치 더하기 위해서 bool 값 리턴
	{
		unf[a] = b; // 두 노드 연결
		return true;
	}
	else
		return false;
}


int main()
{
	//freopen("input.txt", "rt", stdin); // input.txt 파일 읽기

	int n, m, i, a, b, g, sum = 0, cnt = 0;;
	vector<ST> v;
	scanf("%d %d", &n, &m);
	for (i = 1; i <= n; i++)
		unf[i] = i;

	for (i = 1; i <= m; i++)
	{
		scanf("%d %d %d", &a, &b, &g);
		v.push_back(ST(a, b, g));
	}

	sort(v.begin(), v.end()); // 가중치 값으로 오름차순 정렬

	for (i = 0; i < m; i++)
	{
		if (Unf(v[i].numA, v[i].numB) == true) // 서로 연결되면 즉 연결이 안되어있던 상태였다면 가중치 더해줌
		{
			sum += v[i].g;
			cnt++;
			if (cnt == n - 1) // 간선의 개수는 노드 수 -1 이므로 다 연결되었다는 판단
				break;
		}
	}

	printf("%d", sum);
	return 0;
}
