#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>	// cin,cout말고 이제 c에서 제공하는 sanf, printf 사용 - 속도가 조금 더 빠름
#include<vector>
#include<algorithm>
#include<stack> // 스택 자료구조 사용

using namespace std;

// 스택 자료구조를 만든다
// 스택은 먼저 들어간게 아래에 깔리고 맨 마지막에 들어간게
// 먼저 나오는 형식
int stack[100], top = -1;

void Push(const int& x) //top이 현재 stack 마지막 넣은 위치 -1이면 아무것도 없는거
{
	stack[++top] = x;
}

int Pop() // 맨 마지막꺼부터 꺼낸다
{
	return stack[top--];
}

int main() {
	freopen("input.txt", "rt", stdin); // input.txt 파일 읽기
	int n, k;
	scanf("%d %d", &n, &k);
	char str[20] = "0123456789ABCDEF"; // 16진수 표시 용도

	//stack<int> s; // 실제 스택 사용 시
	while (n > 0) // 나머지를 진수표시를 위해 넣는다
	{
		//s.push(n % k); // 스택 푸쉬
		Push(n % k);
		n = n / k;
	}

	//while (s.empty() == false) // 스택이 비어있으면 true
	//{
	//	printf("%c", str[s.top()]); // top은 맨위 자료 참조만 하지 끄집어 내진 않음
	//	s.pop(); // 따라서 여기서 맨위 자료 꺼내줘서 없애야함
	//}
	while (top != -1) // 스택에 있는걸 마지막 꺼부터 꺼내줌
		printf("%c", str[Pop()]);

	return 0;
}