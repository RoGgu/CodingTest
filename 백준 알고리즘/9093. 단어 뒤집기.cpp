#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<string>
#include<vector>
#include<stack>
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
	int N;
	cin >> N;
	cin.ignore(); // 첫 줄 N 읽고 \n 버퍼에 저정해둬서 비워줘야 다음 줄 부터 문자 제대로 읽는다.
	for (int i = 0; i < N; i++)
	{
		stack<char> S;
		string str;
		getline(cin, str);

		for (int j = 0; j < str.size(); j++)
		{
			if (str[j] == ' ')  // 한 단어 구분되면 stack 이용해서 뒤집어서 출력
			{
				while (!S.empty())
				{
					printf("%c", S.top());
					S.pop();
				}
				printf(" ");
			}
			else
			{
				S.push(str[j]); // 단어 이어지면 담아 둔다.
			}
		}
		while (!S.empty()) // 한 문장 끝나고 stack에 담아져 있는 마지막 단어 뒤집어서 출력
		{
			printf("%c", S.top());
			S.pop();
		}
		printf("\n");
	}

	return 0;
}
