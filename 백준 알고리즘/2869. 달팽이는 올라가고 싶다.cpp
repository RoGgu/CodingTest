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
	int A, B, V, cnt = 1;
	cin >> A >> B >> V;

	if (A < V) // 오르는 길이가 총 길이보다 짧다면 하루만에 오르기 떄문에 계산 안한다.
	{
		cnt += (V - A) / (A - B);

		if ((V - A) % (A - B) != 0) // 나머지가 있다면 거리가 조금 모자란 경우라서 하루 추가
			cnt += 1;
	}

	cout << cnt << "\n";
	return 0;
}