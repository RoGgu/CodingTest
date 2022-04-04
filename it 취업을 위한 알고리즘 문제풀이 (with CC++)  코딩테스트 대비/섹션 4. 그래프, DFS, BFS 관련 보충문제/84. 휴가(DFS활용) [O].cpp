#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>	// cin,cout말고 이제 c에서 제공하는 sanf, printf 사용 - 속도가 조금 더 빠름
#include<vector>
#include<queue>
#include<algorithm>

using namespace std;

int n;
int maxCost = -2147000000;
vector<pair<int, int>> map;

void DFS(int v, int sum)
{
	if (v > n)
	{
		if (sum > maxCost) // 총 날짜 했을 때 수익이 더 많을경우 바꿔줌
			maxCost = sum;
	}
	else
	{
		for (int i = v; i <= n; i++)
		{
			if (i + map[i].first <= n + 1) // 오늘 상담 해도 총 소요기간내에 끝내지는지 체크
				DFS(i + map[i].first, sum + map[i].second); // 오늘 상담 한다면 상담 소요기간 이랑 요금 더해줌
			else // 상담 안하면 다음날로 그냥 넘어감
				DFS(v + 1, sum);
		}
	}
}

int main()
{
	//freopen("input.txt", "rt", stdin); // input.txt 파일 읽기
	int a, b;
	scanf("%d", &n);

	map.clear();
	map.push_back(make_pair(0, 0)); // 0번 인덳스 0으로 채워줌;
	for (int i = 1; i <= n; i++)
	{
		scanf("%d %d", &a, &b);
		map.push_back(make_pair(a, b));
	}

	DFS(1, 0);

	printf("%d", maxCost);

	return 0;
}
