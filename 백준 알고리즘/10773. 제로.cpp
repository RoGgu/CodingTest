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
	int n, tmp, sum = 0;
	vector<int> v;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> tmp;
		if (tmp != 0)
			v.push_back(tmp);
		else
			v.pop_back();
	}

	for (int i = 0; i < v.size(); i++)
	{
		sum += v[i];
	}

	cout << sum << "\n";
	return 0;
}