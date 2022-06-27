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

	int n, x, y;
	cin >> n;
	vector<pair<int, int>> map;

	for (int i = 0; i < n; i++)
	{
		cin >> x >> y;
		map.push_back(make_pair(x, y));
	}

	sort(map.begin(), map.end()); // pair형은 sort 작동 잘되서 정렬된다.

	for (int i = 0; i < n; i++)
	{
		cout << map[i].first << " " << map[i].second << "\n";
	}

	return 0;
}