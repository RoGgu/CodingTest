#include<iostream>

using namespace std;
int main() {
	int a, b, sum, i = 0; // a : 입력 수 A, b : 입렵 수 B, sum : 총 수의 합, i : for문 체크 수

	cin >> a >> b; // A, B 입력 받음

	cout << a; // 맨 처음 수 A 출력 후 
	sum = a; // A를 총합의 더한다.
	for (i = a + 1; i <= b; i++) // (A+1)번 부터 돌면서 "+i" 출력하면서 총합에 더해준다.
	{
		cout << '+' << i;
		sum += i;
	}

	cout << '=' << sum; // 마지막에 "=[총 수의 합]" 출력

	return 0;
}
