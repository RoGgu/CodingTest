#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>	// cin,cout말고 이제 c에서 제공하는 sanf, printf 사용 - 속도가 조금 더 빠름
#include<vector>
#include<queue>
#include<algorithm>

using namespace std;

int n;
int minSum = 2147000000;
int maxSum = -2147000000;
vector<int> v;
int numOperator[4];

int calc(int num, int value, int operatorIndex)
{
	int result = 0;
	switch (operatorIndex)
	{
	case 0:
		result = num + value;
		break;
	case 1:
		result = num - value;
		break;
	case 2:
		result = num * value;
		break;
	case 3:
		if (num != 0)
			result = num / value;
		else if (value == 0)
			result = num;
		break;
	}
	return result;
}

void DFS(int l, int sum)
{
	if (l == n) // 모든 수 연산자 계산 끝날떄까지
	{
		if (sum > maxSum)
			maxSum = sum;
		if (sum < minSum)
			minSum = sum;
		return;
	}
	else
	{
		for (int i = 0; i < 4; i++)
		{
			if (numOperator[i] > 0)
			{
				numOperator[i]--; // 인자 사용해서 빼기
				DFS(l + 1, calc(sum, v[l], i)); // 각각 연산자에 맞게 구해진 값을 인자로 넘긴다.
				numOperator[i]++; // 다시 돌아와서 원상으로 복구
			}
		}
	}


}


int main()
{
	//freopen("input.txt", "rt", stdin); // input.txt 파일 읽기
	int tmp;
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
	{
		scanf("%d", &tmp);
		v.push_back(tmp);
	}
	for (int i = 0; i < 4; i++)
	{
		scanf("%d", &tmp);
		numOperator[i] = tmp;
	}

	DFS(1, v[0]); // 처음 수는 더한 상태로 넘겨준다.

	printf("%d\n%d", maxSum, minSum);
	return 0;
}
