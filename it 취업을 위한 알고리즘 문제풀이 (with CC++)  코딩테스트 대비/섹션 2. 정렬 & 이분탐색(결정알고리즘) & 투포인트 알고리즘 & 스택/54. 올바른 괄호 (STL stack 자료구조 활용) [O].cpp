#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>	// cin,cout말고 이제 c에서 제공하는 sanf, printf 사용 - 속도가 조금 더 빠름
#include<vector>
#include<algorithm>
#include<stack>

using namespace std;

int main() {
	//freopen("input.txt", "rt", stdin); // input.txt 파일 읽기
	stack<char> s;
	char a[31];
	int i;
	scanf("%s", &a);
	for (i = 0; a[i] != '\0'; i++)
	{
		if (a[i] == '(') // 여는 괄호면 스택에 넣어줌
			s.push('(');
		else // 닫는 괄호면 '(' 남아있는게 있는지 체크
		{
			if (s.empty() == true) // 없으면'(' ')' 짝이 안 맞는거니 NO출력하고 끝냄
			{
				printf("NO");
				exit(0);
			}
			s.pop(); // 있을경우 하나 제거
		}
	}

	if (s.empty()) // '(' 남은거 없으면 짝 다 맞는거 
		printf("YES");
	else
		printf("NO"); // 아니면 '(' 남아있는거라 ')' 모잘라 짝이 안맞으니 NO

	return 0;
}
