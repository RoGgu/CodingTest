#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>	// cin,cout말고 이제 c에서 제공하는 sanf, printf 사용 - 속도가 조금 더 빠름
#include<vector>
#include<queue>
#include<algorithm>

using namespace std;

vector<int> v; // 숫자 배열
vector<int> path; // 현재 표시할 숫자 저장배열
int ch[16]; // 중복되지 않게 체크
int n, r, sumCnt;

void DFS(int cnt) // 현재 숫자 몇개 저장했는지
{
	if (cnt == r) // 숫자 나열 수가 지정 개수랑 똑같으면 현재까지 배열에 숫자들 프린트하고 빠져나간다
	{
		for (int i = 0; i < path.size(); i++)
		{
			printf("%d ", path[i]);
		}
		printf("\n");
		sumCnt++; // 나열 개수 추가
		return;
	}
	else
	{
		for (int i = 0; i < v.size(); i++)
		{
			if (ch[v[i]] == 0) // 중복 체크
			{
				ch[v[i]] = 1;
				path.push_back(v[i]); // 현재 나열된 숫자 배열에 추가
				DFS(cnt + 1);
				path.pop_back(); // 빠져나왔으니 마지막 꺼 빼줌
				ch[v[i]] = 0;
			}
		}
	}
}



int main()
{
	freopen("input.txt", "rt", stdin); // input.txt 파일 읽기
	int i, tmp;
	scanf("%d %d", &n, &r);

	for (i = 0; i < n; i++)
	{
		scanf("%d", &tmp);
		v.push_back(tmp);
	}
	DFS(0);

	printf("%d", sumCnt);
	return 0;
}
