#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>	// cin,cout말고 이제 c에서 제공하는 sanf, printf 사용 - 속도가 조금 더 빠름
#include<vector>
#include<algorithm>

using namespace std;

int main()
{
	//freopen("input.txt", "rt", stdin); // input.txt 파일 읽기
	int w, h, i, j, k, s, x, y, sum, max = -2147000000;
	scanf("%d %d", &h, &w);
	vector<vector<int>> map(h, vector<int>(w));
	for (i = 0; i < h; i++)
	{
		for (j = 0; j < w; j++)
		{
			scanf("%d", &map[i][j]);
		}
	}
	scanf("%d %d", &y, &x);

	// 모든 좌표 돌면서 4중포문으로 하는방식
	// 개선이 필요하다.
	for (i = 0; i <= h - y; i++) // 범위가 표시되는 곳 까지만 돈다
	{
		for (j = 0; j <= w - x; j++)
		{
			sum = 0;
			for (k = 0; k < x; k++) // 네모난 범위안의 수 전부 더해서 max랑 비교
			{
				for (s = 0; s < y; s++)
				{
					sum += map[i + s][j + k];
				}
			}
			if (sum > max)
				max = sum;
		}
	}

	printf("%d", max);
	return 0;
}
