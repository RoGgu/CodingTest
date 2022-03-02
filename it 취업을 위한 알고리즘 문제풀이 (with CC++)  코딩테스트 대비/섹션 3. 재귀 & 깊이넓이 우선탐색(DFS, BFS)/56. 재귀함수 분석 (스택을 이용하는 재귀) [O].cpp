#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>	// cin,cout말고 이제 c에서 제공하는 sanf, printf 사용 - 속도가 조금 더 빠름
#include<vector>
#include<algorithm>
#include<stack>

using namespace std;

int main() {
	//freopen("input.txt", "rt", stdin); // input.txt 파일 읽기
	stack<int> s;
	int n, i, count = 1, index = 0;
	scanf("%d", &n);
	vector<int> a(n);
	for (i = 0; i < n; i++)
		scanf("%d", &a[i]);
	vector<char> c; // P O 출력할꺼 담아둠ㄴ

	while (count <= n)
	{
		// 스택 맨위에꺼가 기차 순서표랑 맞으면 빼준다
		if (s.empty() == false && s.top() == count)
		{
			s.pop();
			c.push_back('O');
			count++;
		}
		else
		{
			// 아니면 스택에 넣는다
			s.push(a[index]);
			index++;
			c.push_back('P');
		}

		// 더이상 넣을 수 있는게 없는데 빼야되는 수가 기차순서랑 안 맞으면
		// 순서대로 운행 불가능
		if (index == n && s.empty() == false && s.top() != count)
		{
			printf("impossible");
			exit(0);
		}
	}

	for (i = 0; i < c.size(); i++)
		printf("%c", c[i]);

	return 0;
}
