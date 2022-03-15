#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>	// cin,cout말고 이제 c에서 제공하는 sanf, printf 사용 - 속도가 조금 더 빠름
#include<vector>
#include<algorithm>
#include<stack>

using namespace std;

int n, m;
int map[21][21] = { };
int ch[30]; // 경로 중복 체크
int minG = 2147000000; // 가중치 최대 낮은 값

void DFS(int v, int sum)
{
	if (v == n)
	{
		if (sum < minG) // 목표 도달했을때 가중치의 합 비교해서 작으면 바꿔줌
		{
			minG = sum;
		}
	}
	else
	{
		for (int i = 1; i <= n; i++)
		{
			if (map[v][i] > 0 && ch[i] == 0)
			{
				ch[i] = 1;
				DFS(i, sum + map[v][i]); // 이동하는 가중치 값 더해줌
				ch[i] = 0;
			}
		}
	}
}

int main() {
	///freopen("input.txt", "rt", stdin); // input.txt 파일 읽기
	scanf("%d %d", &n, &m);
	int i, a, b, c;
	for (i = 1; i <= m; i++)
	{
		scanf("%d %d %d", &a, &b, &c);
		map[a][b] = c; // 가중치 값을 배열의 값으로 해줌
	}

	ch[1] = 1;
	DFS(1, 0);

	printf("%d", minG);

	return 0;
}
