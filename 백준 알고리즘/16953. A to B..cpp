#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<string>
#include<vector>
#include<queue>
#include<algorithm>
#include<stack>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	freopen("input.txt", "rt", stdin);
	int A, B;
	int ans = -1;
	cin >> A >> B;
	queue<pair<long long int, int> > q;
	q.push(make_pair(A, 1));

	while (!q.empty())
	{
		long long int k = q.front().first;
		int n = q.front().second;
		q.pop();

		if (k == B)
		{
			ans = n;
			break;
		}

		if (k * 2 <= B)
			q.push(make_pair(k * 2, n + 1));
		if (k * 10 + 1 <= B)
			q.push(make_pair(k * 10 + 1, n + 1));
	}

	printf("%d", ans);
	return 0;
}