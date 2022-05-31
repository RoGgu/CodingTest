#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include <string.h>
#include<vector>
#include<queue>
using namespace std;


int main() {
	ios::sync_with_stdio(false);
	freopen("input.txt", "rt", stdin);
	int n, m;
	cin >> n >> m;
	int move[101] = { 0 };
	int dy[101] = { 0 }; // 해당 인덱스 위치에 값은 주사위 굴린 최소 횟수
	queue<int> q;

	for (int i = 0; i < n + m; i++) // 사다리랑 스네이크 모두 n1에서 n2로 이동하는건 똑같으니까 묶어서 세팅
	{
		int n1, n2;
		cin >> n1 >> n2;
		move[n1] = n2;
	}

	q.push(1); // 시작위치 1로 시작

	while (q.empty() == false)
	{
		int n = q.front();
		q.pop();

		for (int i = 1; i <= 6; i++)
		{
			int nn = n + i;
			if (nn > 100)
				continue;

			if (move[nn] != 0) // 사다리나 뱀 걸리면 이동
				nn = move[nn];

			if (dy[nn] == 0) // 한번도 들리지 않아야 최소값 세팅가능
			{
				dy[nn] = dy[n] + 1;
				q.push(nn);
			}
		}
	}

	cout << dy[100] << "\n";
	return 0;
}