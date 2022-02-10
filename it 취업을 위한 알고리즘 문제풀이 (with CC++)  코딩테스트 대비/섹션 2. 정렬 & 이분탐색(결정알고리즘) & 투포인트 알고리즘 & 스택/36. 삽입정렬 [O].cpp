#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>	// cin,cout말고 이제 c에서 제공하는 sanf, printf 사용 - 속도가 조금 더 빠름
#include<vector>
#include<algorithm>

using namespace std;

// 삽입 정렬
// i 는 1부터 돌고
// j 는 i -1 부터 0까지 돈다
// a[i] 를 tmp 에 담고 
// j를 돌면서 a[j] 가 tmp 보다 크면 a[j] 값을 a[j+1]에다가 넣는다
// 즉 클경우 한칸씩 뒤로 넣고
// 그러다가 tmp보다 작은 수를만나면 break
// 현재 j+1 에다가 tmp 값을 넣는다

// 즉 a[i]를 tmp 넣고 앞으로 돌면서 자기보다 큰수는 뒤로 밀고
// 만약 체크하다가 자기보다 작은수 만나면 그수 바로뒤에 tmp값을 넣는다

int main()
{
	//freopen("input.txt", "rt", stdin); // input.txt 파일 읽기
	int a[101];
	int n, i, j, tmp;
	scanf("%d", &n);

	for (i = 0; i < n; i++)
		scanf("%d", &a[i]);

	for (i = 1; i < n; i++)
	{
		tmp = a[i];	// 비교 값 a[i]를 담는다
		for (j = i - 1; i >= 0; j--)	// tmp 앞에 수부터 0까지 돈다
		{
			if (a[j] > tmp)	// tmp 보다 클경우 뒤로 한칸 미뤄준다
			{
				a[j + 1] = a[j];
			}
			else
				break;
		}
		a[j + 1] = tmp;	// tmp보다 작은거 만낫을떄 끝나니까 바로 그뒤에 tmp를 넣어준다
	}

	for (i = 0; i < n; i++)
		printf("%d", a[i]);

	return 0;
}
