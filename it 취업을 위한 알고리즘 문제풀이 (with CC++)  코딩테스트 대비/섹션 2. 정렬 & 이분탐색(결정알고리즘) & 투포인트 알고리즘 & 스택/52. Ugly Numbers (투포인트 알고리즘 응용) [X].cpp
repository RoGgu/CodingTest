#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>	// cin,cout말고 이제 c에서 제공하는 sanf, printf 사용 - 속도가 조금 더 빠름
#include<vector>
#include<algorithm>

using namespace std;
int a[1501];
int main() {
	freopen("input.txt", "rt", stdin); // input.txt 파일 읽기

	int n, i, p2, p3, p5, min = 0;
	scanf("%d", &n);
	a[1] = 1;
	p2 = p3 = p5 = 1;
	for (i = 2; i <= n; i++)
	{
		if (a[p2] * 2 < a[p3] * 3)
			min = a[p2] * 2;
		else
			min = a[p3] * 3;
		if (a[p5] * 5 < min)
			min = a[p5] * 5;
		if (min == a[p2] * 2)
			p2++;
		if (min == a[p3] * 3)
			p3++;
		if (min == a[p5] * 5)
			p5++;
		a[i] = min;
	}
	printf("%d\n", a[n]);
	return 0;
}
