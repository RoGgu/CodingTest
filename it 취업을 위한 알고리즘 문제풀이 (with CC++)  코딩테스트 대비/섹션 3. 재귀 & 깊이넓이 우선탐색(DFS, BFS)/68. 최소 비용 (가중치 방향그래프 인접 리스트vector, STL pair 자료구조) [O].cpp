#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>	// cin,cout말고 이제 c에서 제공하는 sanf, printf 사용 - 속도가 조금 더 빠름
#include<vector>
#include<algorithm>

#define x first // first 쓰기 싫으면 x로 대체가능
#define y second //  second 쓰기 싫으면 y로 대체가능

using namespace std;

// pair<[TYPE], [TYPE]> 
// 페어는 두개의 데이터가 쌍으로 이루어져있는 데이터
// pair 생성 방식
// - pair<int, int> p(1,5);
// - [기존 pair타입 받는거에].make_pair(1,5);
// pair 데이터 접근 방식
// - pair.first = 첫 번째 데이터
// - pair.second = 두 번째 데이터


int n, m;
int cost = 2147000000;
int ch[30];
vector<pair<int, int>> map[30]; // pair타입으로 vector생성



void DFS(int v, int sum)
{
	if (v == n)
	{
		if (sum < cost)
			cost = sum;
	}
	else
	{
		for (int i = 0; i < map[v].size(); i++)
		{
			if (ch[map[v][i].first] == 0) // 연결 노드가 이미 간 곳인지 체큰
			{
				ch[map[v][i].first] = 1;
				DFS(map[v][i].first, sum + map[v][i].second); // first가 연결 노드,  second가 가중치
				ch[map[v][i].first] = 0;
			}
		}
	}
}

int main() {
	//freopen("input.txt", "rt", stdin); // input.txt 파일 읽기
	int i, a, b, c;
	scanf("%d %d", &n, &m);
	for (i = 1; i <= m; i++)
	{
		scanf("%d %d %d", &a, &b, &c);
		map[a].push_back(make_pair(b, c));
	}

	ch[1] = 1;
	DFS(1, 0);

	printf("%d", cost);
	return 0;
}
