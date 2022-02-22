#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>	// cin,cout말고 이제 c에서 제공하는 sanf, printf 사용 - 속도가 조금 더 빠름
#include<vector>
#include<algorithm>

using namespace std;

int main()
{
	//freopen("input.txt", "rt", stdin); // input.txt 파일 읽기
	int n = 9, i, j, index;
	float tmp;
	vector<vector<int>> map(n, vector<int>(n));
	vector<int> average(n);
	for (i = 0; i < n; i++)
	{
		tmp = 0;
		for (j = 0; j < n; j++)
		{
			scanf("%d", &map[i][j]);
			tmp += map[i][j];
		}
		//average[i] = (tmp / (float)n) + 0.5; 0.5f; 그냥 소수에 0.5 더하고 정수로 나누는 방법도 있음 ex) 47.7 + 0.5 = 48.3 -> 48

		average[i] = tmp / n; // 평균값 일단 넣고
		tmp = tmp / n * 10;	// 소수 첫번째 자리값 구하기위해 계산
		tmp = (int)tmp % 10;
		if (tmp >= 5) // 소수 첫번 째 자리수가 5보다 크면 반올림 하니까 평균 1 증가
			average[i]++;
		printf("%d", average[i]); // 평균 출력


		index = 0; // 평균 가장 가까운 값 인덱스
		for (j = 1; j < n; j++)
		{
			if (abs(map[i][j] - average[i]) < abs(map[i][index] - average[i]))	// 절대 값 차이로 구한다
			{
				index = j;
			}
			else if (abs(map[i][j] - average[i]) == abs(map[i][index] - average[i])) // 절대값 차이가 같을경우 큰 수를 답으로 한다.
			{
				if (map[i][index] < map[i][j])
					index = j;
			}
		}
		printf("%d\n", map[i][index]); // 평균과 가장 가까운 값 출력
	}

	return 0;
}
