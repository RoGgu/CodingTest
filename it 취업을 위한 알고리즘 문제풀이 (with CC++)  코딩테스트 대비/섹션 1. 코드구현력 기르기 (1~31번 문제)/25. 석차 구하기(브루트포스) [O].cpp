#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>	// cin,cout말고 이제 c에서 제공하는 sanf, printf 사용 - 속도가 조금 더 빠름
#include<vector>	// vector 사용을 위해

using namespace std;
int main() {
	//freopen("input.txt", "rt", stdin); // input.txt 파일 읽기
	int i, j, n, num, temp; // i,j : for문 카운트, n : 점수의 개수, num : i for문 기준 점수, temp : 해당 i 점수의 등수
	scanf("%d", &n);
	vector<int> a(n); // 점수 배열

	for (i = 0; i < n; i++)
	{
		scanf("%d", &a[i]);
	}

	for (i = 0; i < n; i++)
	{
		num = a[i];
		temp = 1;
		for (j = 0; j < n; j++)
		{
			if (num < a[j])	// 처음기준 1등이라고 하고 자기보다 큰 수 발견할때마다 등수 내려감
				temp++;
		}
		printf("%d ", temp);
	}

	return 0;
}
