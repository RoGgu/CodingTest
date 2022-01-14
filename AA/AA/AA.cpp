#define _CRT_SECURE_NO_WARNINGS
//#include<stdio.h>
#include<iostream>

using namespace std;
int main() {
	freopen("input.txt", "rt", stdin); // input.txt 파일 읽기
	int n, i, a, max = -2147000000, min = 2147000000; // n : 총수의 갯 수 , i : for문 반복 횟 수, a 입력받은 i 번째 수 , max : 최대 값, max : 최솟 값

	cin >> n; // 총 수의 갯 수 입력 받고
	for (i = 0; i < n; i++)	// for문 돌면서 최대값 최솟값 구함
	{
		cin >> a;
		if (a > max)
			max = a;
		else if (a < min)
			min = a;
	}

	cout << max - min; // 차이 출력

	return 0;
}
