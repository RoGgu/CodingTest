#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>	// cin,cout말고 이제 c에서 제공하는 sanf, printf 사용 - 속도가 조금 더 빠름
#include<vector>
#include<queue>
#include<algorithm>

using namespace std;

// c는 두가지 두가지 버전으로 재귀적으로 나뉘어진다
// 자기가 참여한거, 자기가 참여하지 않느거
// ex) 5C3이면 4C2 + 4C3이 된다.
// 4C2는 5가 낄꺼니까 4까지 2개만 구하고,
// 4C3은 5가 안 끼니까 4까지에서 3개다 구하는걸로 나뉘어진다.

// 메모리제이션 사용 
// 또한 재귀적으로 돌 때 중복되는거 다시 돌 필요 없게하기위해서
// 미리 배열로 저장해놓고 재활용한다.  - 이것이 메모리제이션

int map[100][100] = { 0 };

int DFS(int n, int r)
{
	if (map[n][r] > 0) // 0 보다 크면 이미 구해진 수 
		return map[n][r];

	if (n == r || r == 0)
		return 1;
	else
		return map[n][r] = DFS(n - 1, r - 1) + DFS(n - 1, r); // 메모리제이션 사용을 위해 갑 저장
}


int main()
{
	//freopen("input.txt", "rt", stdin); // input.txt 파일 읽기
	int n, r;
	scanf("%d %d", &n, &r);

	printf("%d", DFS(n, r));
	return 0;
}
