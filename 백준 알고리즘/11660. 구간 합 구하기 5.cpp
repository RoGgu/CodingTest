#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<string.h>
#include<vector>
#include<queue>
#include <unordered_map>
#include<algorithm>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	freopen("input.txt", "rt", stdin);
	int n, m, tmp, res = 0;;
	cin >> n >> m;
	vector<vector<int>> dy(n + 1, vector<int>(n + 1, 0)); // 구간별 전부 더 했을때에 합을 세팅
	for (int x = 1; x <= n; x++) // x가 행이고 y가 열이다.
	{
		for (int y = 1; y <= n; y++)
		{
			cin >> tmp;
			dy[x][y] = dy[x - 1][y] + dy[x][y - 1] - dy[x - 1][y - 1] + tmp; // 현재 좌표 위까지 전부 더한거 + 왼쪽까지 전부 더한거 + 중복되는 부분 뺴고 입력 수 더하면 현재 좌표까지 더한 총 수가 세팅된다.
		}
	}

	for (int i = 0; i < m; i++)
	{
		int x1, y1, x2, y2;
		cin >> x1 >> y1 >> x2 >> y2;

		res = dy[x2][y2] - dy[x1 - 1][y2] - dy[x2][y1 - 1] + dy[x1 - 1][y1 - 1]; // 현재 좌표까지의 합 - x1-1 까지의합 - y1-1까지의 합 + 죽복되서 뺴진 부분 더한다.

		cout << res << "\n";
	}

	return 0;
}