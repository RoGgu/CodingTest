#define _CRT_SECURE_NO_WARNINGS
//#include<stdio.h>
#include<iostream>

using namespace std;
int main() {
	int n, m, i, sum = 0;
	cin >> n >> m;

	for (i = 1; i <= n; i++)
	{
		if (i % m == 0) // m으로 나눠서 나머지가 0이면 i는 m의 배수
			sum += i;
	}

	cout << sum;
	return 0;
}
