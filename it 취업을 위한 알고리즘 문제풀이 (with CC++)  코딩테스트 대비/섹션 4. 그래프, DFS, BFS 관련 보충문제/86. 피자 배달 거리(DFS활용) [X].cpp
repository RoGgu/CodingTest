
#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>	// cin,cout말고 이제 c에서 제공하는 sanf, printf 사용 - 속도가 조금 더 빠름
#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
#include<cstdlib>

using namespace std;

vector<pair<int, int>> pz; // 피자 집 위치
vector<pair<int, int>> hs; // 집 위치
int ch[20]; // 현재 담아둔 피자집 조합 배열
int m, res = 2147000000;
int sum = 0, dis;

// 총 피자집에서 살아남아야하는 피자집 개수 조합을 구한 후 전부 최소거리 측정


void DFS(int s, int L)
{
	if (L == m) // 조합의 수가 피자집 생존 개수랑 똑같으면 최소거리 체크
	{
		sum = 0;
		for (int i = 0; i < hs.size(); i++)
		{
			int x1 = hs[i].first;
			int y1 = hs[i].second;
			dis = 2147000000;
			for (int j = 0; j < m; j++)
			{
				int x2 = pz[ch[j]].first;
				int y2 = pz[ch[j]].second;

				dis = min(dis, abs(x1 - x2) + abs(y1 - y2));
			}
			sum += dis;
		}

		if (sum < res) // 최소 거리 적용
			res = sum;
	}
	else
	{
		for (int i = s; i < pz.size(); i++) // 조합 구하는 공식
		{
			ch[L] = i;
			DFS(i + 1, L + 1);
		}
	}
}

int main()
{
	//freopen("input.txt", "rt", stdin); // input.txt 파일 읽기
	int n, tmp;
	cin >> n >> m;

	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			cin >> tmp;
			if (tmp == 1)
				hs.push_back(make_pair(i, j));
			else if (tmp == 2)
				pz.push_back(make_pair(i, j));
		}
	}

	DFS(0, 0);
	cout << res;
	return 0;
}
