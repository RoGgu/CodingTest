#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>	// cin,cout말고 이제 c에서 제공하는 sanf, printf 사용 - 속도가 조금 더 빠름
#include<vector>
#include<queue>
#include<algorithm>

using namespace std;
struct Data
{
	int money;
	int when;
	Data(int a, int b)
	{
		money = a;
		when = b;
	}
	bool operator<(Data& b)
	{
		return when > b.when;
	}
};

int main()
{
	//freopen("input.txt", "rt", stdin); // input.txt 파일 읽기
	int n, i, j = 0, a, b, res = 0, max = -2147000000;
	vector<Data>T;
	priority_queue<int> pQ;
	scanf("%d", &n);
	for (i = 0; i < n; i++)
	{
		scanf("%d %d", &a, &b);
		T.push_back(Data(a, b));
		if (b > max)
			max = b;
	}

	sort(T.begin(), T.end());
	for (i = max; i > 0; i--)
	{
		for (; j < T.size(); j++)
		{
			if (T[j].when < i)
				break;
			else if (T[j].when == i)
				pQ.push(T[j].money);
		}

		if (!pQ.empty())
		{
			res += pQ.top();
			pQ.pop();
		}
	}


	printf("%d", res);
	return 0;
}
