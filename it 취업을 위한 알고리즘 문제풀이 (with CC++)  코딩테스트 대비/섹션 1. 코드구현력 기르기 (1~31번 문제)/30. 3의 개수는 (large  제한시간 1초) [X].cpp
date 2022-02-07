#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>	// cin,cout말고 이제 c에서 제공하는 sanf, printf 사용 - 속도가 조금 더 빠름
#include<vector>
#include<algorithm>

using namespace std;

// 10의 자리에 3이 오는경우로 카운터

// 3가지 경우로 체크 십의자리의 수가 3보다 큰경우, 같은경우, 작은경우

// 십의 자리에 3이 처음나타는 경우는 30 - 30대는 3(0~9) 10개
// 그담은 100대 130, 230... ----- 13(0~9) 10개, 23(0~9) 10개 .....

// 구역 3개로 나눔 10의자리수는 cur 그왼쪽은 lt 그오른쪽 rt, k는 자릿수
// ex)10의 자리 3 구할때 5367 -> 53: lt, 6 :cur, 7 :rt
// 10의 자리의 3이 나오는 식 클경우 (lt+1)*10, 작을경우 lt*10 , 같을 경우 (lt * 10 ) + (rt + 1) ----- k 는 자릿 수만큼의 값

// ex) 5367 자릿수별로 구분
// lt	cur		rt		k	
// 536	7		0		1		// 1의자리 3의 갯수 구할떄
// 53	6		7		10		// 10의자리 ""
// 5	3		67		100		// 100의자리 ""
// 0	5		367		1000	// 1000의자리 ""


int main() {
	//freopen("input.txt", "rt", stdin); // input.txt 파일 읽기
	int n, lt = 1, cur, rt, k = 1, res = 0;

	scanf("%d", &n);

	while (lt != 0)
	{
		lt = n / (k * 10);
		cur = (n / k) % 10;
		rt = n % k;
		//printf("lt : %d,  cur : %d, rt : %d", lt, cur, rt);

		if (cur > 3)
		{
			res = res + (lt + 1) * k;
		}
		else if (cur < 3)
		{
			res = res + (lt * k);
		}
		else
		{
			res = res + (lt * k) + (rt + 1);
		}

		k = k * 10;
	}

	printf("%d", res);
	return 0;
}
