#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>	// cin,cout말고 이제 c에서 제공하는 sanf, printf 사용 - 속도가 조금 더 빠름
#include<vector>
#include<algorithm>

using namespace std;

bool check(int n, vector<vector<int>>& a, const int& posX, const int& posY)
{
	// 상화좌우체크를 를 위한 배열
	int dx[] = { -1, 1, 0, 0 };
	int dy[] = { 0, 0, -1, 1 };

	for (int i = 0; i < 4; i++)
	{
		int checkX = posX + dx[i];
		int checkY = posY + dy[i];

		if (checkX >= 0 && checkX < n && checkY >= 0 && checkY < n)
		{
			// 자기 배열 넘어가는 테투리일 경우 무시 
			// 자기보다 큰 수 나오면 봉우리 아니니까 바로 false 리턴
			if (a[posX][posY] <= a[checkX][checkY])
				return false;
		}
	}
	return true;
}


int main()
{
	//freopen("input.txt", "rt", stdin); // input.txt 파일 읽기
	int n, i, j, tmp, res = 0;
	scanf("%d", &n);
	vector<vector<int>> map;
	//vector<vector<int>> map(n, vector<int>(n)); // 행, 열 초기화
	for (i = 0; i < n; i++)
	{
		vector<int> b;
		map.push_back(b);	// 초기화 안하고 push 하는법
		for (j = 0; j < n; j++)
		{
			scanf("%d", &tmp);
			map[i].push_back(tmp);
		}
	}

	for (i = 0; i < n; i++)
	{
		for (j = 0; j < n; j++)
		{
			// 봉우리인지 체크
			bool bong = check(n, map, i, j);

			if (bong == true)
				res++;
		}
	}

	printf("%d", res);
	return 0;
}
