#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>	// cin,cout말고 이제 c에서 제공하는 sanf, printf 사용 - 속도가 조금 더 빠름
#include<vector>
#include<algorithm>

using namespace std;

int main()
{
	//freopen("input.txt", "rt", stdin); // input.txt 파일 읽기
	int n, i, j, res = 0;;
	scanf("%d", &n);
	vector<int> front(n); // 앞에서 본 수
	vector<int> right(n); // 오른쪽에서 본 수
	for (i = 0; i < n; i++)
		scanf("%d", &front[i]);
	for (i = 0; i < n; i++)
		scanf("%d", &right[i]);

	vector<vector<int>> map(n, vector<int>(n));
	for (i = 0; i < n; i++)
	{
		for (j = 0; j < n; j++)
		{
			// 앞 오른쪽 본것중에서 작은쪽의 수를 넣는다
			if (front[j] <= right[i])
				map[i][j] = front[j];
			else
				map[i][j] = right[i];

			res += map[i][j];
		}
	}

	printf("%d", res);
	return 0;
}
