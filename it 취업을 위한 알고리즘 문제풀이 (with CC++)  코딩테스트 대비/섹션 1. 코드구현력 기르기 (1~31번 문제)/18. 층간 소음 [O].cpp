#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>	// cin,cout말고 이제 c에서 제공하는 sanf, printf 사용 - 속도가 조금 더 빠름

int main() {
	//freopen("input.txt", "rt", stdin); // input.txt 파일 읽기
	int n, m, num, i, time = 0, max = -2147000000, result = -1;	// n : 측정 갯수, m : 경보음 기준치, num : 측정 소음, i : for문 카운트, time : 경보음 지속 시간, max : 최대 지속시간, result : 최종적으로 최대 경보음 지속시간(경보음 울린적 없을땐 -1)
	scanf("%d %d", &n, &m);

	for (i = 0; i < n; i++)
	{
		scanf("%d", &num);
		if (num > m)	// 경보음 기준치 넘는지 체크
		{
			time++;
			if (time > max)	// 경보음 지속시간이 최대시간보다 높을 경우에만 최대시간으로 다시 세팅
			{
				max = time;
				result = max;
			}
		}
		else
		{
			time = 0;
		}
	}

	printf("%d", result);
	return 0;
}
