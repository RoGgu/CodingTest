#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>	// cin,cout말고 이제 c에서 제공하는 sanf, printf 사용 - 속도가 조금 더 빠름
#include<vector>
#include<algorithm>

using namespace std;

// dy는 다이나믹 맵
// 자기 x갚 앞에 다이나믹 + 자기 y 값 위 다이나믹 값 - 교집함 + 원래 그 위치에있는 값
// dy[i][j] = dy[i][j-1] + dy[i-1][j] - dy[i-1][j-1] + map[i][j];

// 특정 범위를 가지는 dy값 구하기
// dy[i][j] = dy[i-y][j] - dy[i][j-x] + dy[i-y][j-x]

int main()
{
	//freopen("input.txt", "rt", stdin); // input.txt 파일 읽기
	int w, h, i, j, x, y, tmp, max = -2147000000;
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

	vector<vector<int>> dy(h, vector<int>(w));

	// dy 맵 완성
	for (i = 0; i < h; i++)
	{
		for (j = 0; j < w; j++)
		{
			tmp = 0;
			if (i - 1 >= 0)
				tmp += dy[i - 1][j];
			if (j - 1 >= 0)
				tmp += dy[i][j - 1];

			if (i - 1 >= 0 && j - 1 >= 0) // 중복되서 더해진 교집함 범위 뺸다.
				tmp -= dy[i - 1][j - 1];

			tmp += map[i][j];
			dy[i][j] = tmp;
		}
	}

	// dy 범위로 체크하면서 돈다
	for (i = y - 1; i < h; i++) // 최소 범위 되는 곳부터 돔
	{
		for (j = x - 1; j < w; j++)
		{
			tmp = 0;
			tmp = dy[i][j];

			if (i - y >= 0)
				tmp -= dy[i - y][j];
			if (j - x >= 0)
				tmp -= dy[i][j - x];

			if (i - y >= 0 && j - x >= 0) // 중복해서 빠진 부분 더한다.
				tmp += dy[i - y][j - x];

			if (tmp > max)
				max = tmp;
		}
	}

	printf("%d", max);
	return 0;
}
