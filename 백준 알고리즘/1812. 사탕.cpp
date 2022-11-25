#define _CRT_SECURE_NO_WARNINGS
#include<iostream>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	freopen("input.txt", "rt", stdin);
	int n;
	int arr[1000], sum = 0;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> arr[i];
		sum += arr[i];
	}

	sum /= 2; // 나누기 2를 하면 전체 사탕의 개 수를 알 수 있다

	for (int i = 0; i < n; i++)
	{
		int tmp = 0;
		for (int j = 0; j < n; j += 2)
		{
			tmp += arr[(i + j) % n];
		}

		cout << tmp - sum << '\n';
	}

	return 0;
}
