#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>	// cin,cout말고 이제 c에서 제공하는 sanf, printf 사용 - 속도가 조금 더 빠름
#include<vector>
#include<algorithm>
#include<stack>

using namespace std;

// vector 인접 리스트로 하면 이중배열로 n * n 크기만큼 배열만들 필요 업시
// n만큼 vector배열 만들고 열결된 간선들만 각각 붙여주면 돼서 더 좋다
// 메모리 용량도 줄고 체크해야할 for문 수도 줄어든다

vector<int> map[30];
int ch[30];
int n, cnt = 0;

void DFS(int num)
{
	if (num == n) // n 도착지점 도착하면 카운트
	{
		cnt++;
	}
	else
	{
		for (int i = 0; i < map[num].size(); i++) // 연결되어 있는 간선 전부 체크
		{
			if (ch[map[num][i]] == 0) // 이미 지나온 값은 패스
			{
				ch[map[num][i]] = 1;
				DFS(map[num][i]);
				ch[map[num][i]] = 0;
			}
		}
	}
}

int main() {
	//freopen("input.txt", "rt", stdin); // input.txt 파일 읽기
	int m, i, j, a, b;
	scanf("%d %d", &n, &m);
	for (i = 1; i <= m; i++)
	{
		scanf("%d %d", &a, &b);
		map[a].push_back(b); // vector에 연결된 간선 정보 세팅해줌
	}

	ch[1] = 1; // 처음 1번부터 시작하니 1번 체크
	DFS(1);

	printf("%d", cnt);

	return 0;
}
