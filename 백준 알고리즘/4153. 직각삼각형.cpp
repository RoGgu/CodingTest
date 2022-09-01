#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<string>
#include<vector>
#include<queue>
#include<algorithm>
#include<cmath>
#include<map>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	freopen("input.txt", "rt", stdin);
	int x, y, z;
	int temp = 0;

	while (true)
	{
		cin >> x >> y >> z;
		if (x == 0 && y == 0 && z == 0)
			break;

		if (x > y)
		{
			temp = y;
			y = x;
			x = temp;
		}
		if (y > z)
		{
			temp = z;
			z = y;
			y = temp;
		}

		if (z * z == x * x + y * y) 
			cout << "right\n";
		else
			cout << "wrong\n";

	}

	return 0;
}
