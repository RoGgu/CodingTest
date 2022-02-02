#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>	// cin,cout말고 이제 c에서 제공하는 sanf, printf 사용 - 속도가 조금 더 빠름
#include<vector>	// vector 사용을 위해
#include<algorithm>
using namespace std;

int main() {
	//freopen("input.txt", "rt", stdin); // input.txt 파일 읽기
	int i, j, n, count; // i,j : for문 카운트, n : 총 선수 수, count : 각 선수별 등수
	scanf("%d", &n);
	vector<int> a(n); // a : 선수들 점수

	for (i = 0; i < n; i++)
	{
		scanf("%d", &a[i]);
		count = 1 + i;
		for (j = 0; j < i; j++)	// 자기 앞에 선수들 돌면서 자기보다 점수 낮으면 추월가능하니 등수 낮춤
		{
			if (a[j] < a[i])
				count--;
		}
		printf("%d ", count);
	}

	return 0;
}
