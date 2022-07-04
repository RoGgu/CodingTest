#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<string.h>
#include<vector>
#include<queue>
#include <unordered_map>
#include<algorithm>
using namespace std;

string WB[8] =
{
	"WBWBWBWB",
	"BWBWBWBW",
	"WBWBWBWB",
	"BWBWBWBW",
	"WBWBWBWB",
	"BWBWBWBW",
	"WBWBWBWB",
	"BWBWBWBW"
};
string BW[8] =
{
	"BWBWBWBW",
	"WBWBWBWB",
	"BWBWBWBW",
	"WBWBWBWB",
	"BWBWBWBW",
	"WBWBWBWB",
	"BWBWBWBW",
	"WBWBWBWB"
};

int CheckBoard(const vector<string>& map, const string board[8], int y, int x)
{
	int cnt = 0;
	for (int i = 0; i < 8; i++)
	{
		for (int j = 0; j < 8; j++) // 체스 판 모양과 다르면 색 바까야해서 카운트
		{
			if (map[y + i][x + j] != board[i][j])
				cnt++;
		}

	}
	return cnt;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	freopen("input.txt", "rt", stdin);
	int n, m, res = 2147000000;
	cin >> n >> m;
	vector<string> map(n);

	for (int i = 0; i < n; i++)
		cin >> map[i];

	for (int y = 0; y + 8 <= n; y++)
	{
		for (int x = 0; x + 8 <= m; x++)
		{
			int tmp;
			tmp = min(CheckBoard(map, BW, y, x), CheckBoard(map, WB, y, x)); // 첫 시작이 화이트랑 블랙일 경우 두가지 비교해서 더 작은거 세팅
			if (tmp < res)
				res = tmp;
		}
	}

	cout << res << "\n";
	return 0;
}