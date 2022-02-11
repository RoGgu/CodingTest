#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>	// cin,cout말고 이제 c에서 제공하는 sanf, printf 사용 - 속도가 조금 더 빠름
#include<vector>
#include<algorithm>

using namespace std;

int main()
{
	//freopen("input.txt", "rt", stdin); // input.txt 파일 읽기
	int n, m, i, posA = 0, posB = 0, index = 0;
	scanf("%d", &n);
	vector<int> a(n);
	for (i = 0; i < n; i++)
		scanf("%d", &a[i]);

	scanf("%d", &m);
	vector<int> b(m);
	for (i = 0; i < m; i++)
		scanf("%d", &b[i]);

	vector<int>res(n + m);

	// 배열 하나가 다 끝날떄까지 돈다
	while (posA < n && posB < m)
	{
		if (a[posA] <= b[posB]) // 먼저 작은 수 발견되면 하나씩 넣음
		{
			res[index] = a[posA];
			posA++;
		}
		else
		{
			res[index] = b[posB];
			posB++;
		}
		index++;
	}

	// 어떤 배열이 더 남았는지 몰라서 체크하고 남은거 돌려줌
	while (posA < n)
	{
		res[index] = a[posA];
		posA++;
		index++;
	}
	while (posB < m)
	{
		res[index] = b[posB];
		posB++;
		index++;
	}

	for (i = 0; i < n + m; i++)
		printf("%d ", res[i]);
	return 0;
}
