#include<iostream>

using namespace std;
int main() {
	int n, i, sum = 0;

	cin >> n;

	cout << 1;
	sum = 1;
	for (i = 2; i < n; i++)
	{
		if (n % i == 0)
		{
			cout << " + ";
			cout << i;
			sum += i;
		}
	}

	cout << " = " << sum;

	return 0;
}
