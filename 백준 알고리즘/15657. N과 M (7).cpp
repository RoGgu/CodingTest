#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<string.h>
#include<vector>
#include<algorithm>
using namespace std;

const int MAX = 7;

int N, M;
int arr[MAX];
int visited[MAX];

void Fun(int idx)
{
	if (idx == M)
	{
		for (int i = 0; i < M; i++)
		{
			cout << arr[visited[i]] << " ";
		}
		cout << "\n";
		return;
	}

	for (int i = 0; i < N; i++)
	{
		visited[idx] = i;
		Fun(idx + 1);
	}
}

int main(void)
{
	ios_base::sync_with_stdio(0);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> N >> M;

	for (int i = 0; i < N; i++)
	{
		cin >> arr[i];
	}
	sort(arr, arr + N);
	Fun(0);

	return 0;
}