#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>	// cin,cout말고 이제 c에서 제공하는 sanf, printf 사용 - 속도가 조금 더 빠름

using namespace std;
int main() {
	//freopen("input.txt", "rt", stdin); // input.txt 파일 읽기
	int n, sum = 0, c = 1, d = 9, res = 0; // n : 입력 수 , sum : 자릿수 값 미리 계산한 수, c : 계산할 때 자릿 수, d : 같은 자릿수의 총 갯수, res : 자릿수들의 합 총 결과 값
	scanf("%d", &n);

	while (sum + d < n)	// 현재 최고 자릿수 밑에는 9 + 90*2 + 900*3.. 와 같이 자릿수가 같은 수 * 자릿 수 해서 미리 더 해줌  
	{
		res = res + (c * d);
		sum = sum + d; // 9 , 99, 999 이렇게 미리 더한 수의 갯수
		c++;	// 자릿수 증가
		d = d * 10;
	}
	res += (n - sum) * c; // 미리 자릿수 계산한거 빼고 나머지 수 * 자릿 수

	printf("%d", res);
	return 0;
}
