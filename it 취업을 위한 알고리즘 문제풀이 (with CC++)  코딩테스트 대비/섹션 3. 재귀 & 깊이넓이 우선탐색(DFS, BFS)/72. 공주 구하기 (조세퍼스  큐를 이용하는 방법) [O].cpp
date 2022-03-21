#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>	// cin,cout말고 이제 c에서 제공하는 sanf, printf 사용 - 속도가 조금 더 빠름
#include<vector>
#include<queue>
#include<algorithm>

using namespace std;

// q의 왕자들 담아두고 돌면서 q에서 뺴서 뒤로 밀어넣는다
// 그러다 k번째가 되면 그 왕자는 안넣고 k외치는 cnt 초기화

int main()
{
	//freopen("input.txt", "rt", stdin); // input.txt 파일 읽기
	int i, n, k, tmp, cnt = 1;
	queue<int> q;
	scanf("%d %d", &n, &k);

	for (i = 1; i <= n; i++)
		q.push(i);

	while (!q.empty())
	{
		tmp = q.front();
		q.pop();

		if (cnt == k) // k번쨰 되면 퇴출되므로 cnt 1부터 다시 불러줌
			cnt = 1;
		else
		{
			cnt++;
			q.push(tmp);
		}
	}

	printf("%d", tmp); // 마지막 왕자가 tmp로 남아있으니 tmp출력
	return 0;
}
