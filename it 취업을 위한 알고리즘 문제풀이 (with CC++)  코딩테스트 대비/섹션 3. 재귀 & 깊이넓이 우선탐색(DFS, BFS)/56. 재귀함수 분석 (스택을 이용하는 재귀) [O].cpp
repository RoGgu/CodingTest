#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>	// cin,cout말고 이제 c에서 제공하는 sanf, printf 사용 - 속도가 조금 더 빠름
#include<vector>
#include<algorithm>

using namespace std;

void recur(int x) // 재귀 함수
{
	if (x == 0) // 특정 조건, 종료지점에 재귀 끝내게 만듬
		return;
	else // 아직 종료지점 전이라서 계속 함
	{
		recur(x - 1); // 여기서 현재 상태 스택에 저장하고 다시 함수로 새로 들어감
		printf("%d ", x); // 재귀가 끝나고 스택 최상단 1부터 출력되면서 모든 재귀함수 돌면서 마무리
	}
}

int main()
{
	//freopen("input.txt", "rt", stdin); // input.txt 파일 읽기
	int n;
	scanf("%d", &n);
	recur(n);
	return 0;
}
