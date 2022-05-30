#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include <string.h>
#include<vector>
#include<queue>
using namespace std;

int n, cnt = 0;
char map[100][100];
bool isVisited[100][100] = { false };

int dy[4] = { -1,1,0,0 };
int dx[4] = { 0,0,-1,1 };

void dfs(int x, int y) {
	isVisited[x][y] = true;
	for (int i = 0; i < 4; i++) {
		int nx = x + dx[i];
		int ny = y + dy[i];

		if (nx < 0 || nx >= n || ny < 0 || ny >= n)
			continue;

		if (!isVisited[nx][ny] && map[x][y] == map[nx][ny])
			dfs(nx, ny);
	}
}

int main() {
	ios::sync_with_stdio(false);
	freopen("input.txt", "rt", stdin);
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> map[i];
	}

	// 일반 사람 체크
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (!isVisited[i][j]) {
				dfs(i, j);
				cnt++;
			}
		}
	}
	cout << cnt << endl;

	//적록색약 체크
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (map[i][j] == 'G')  // 그린 색깔 레드로 다 바꿔준다.
				map[i][j] = 'R';
		}
	}
	memset(isVisited, false, sizeof(isVisited)); // 방문 초기화

	cnt = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (!isVisited[i][j]) {
				dfs(i, j);
				cnt++;
			}
		}
	}

	cout << cnt << endl;
	return 0;
}