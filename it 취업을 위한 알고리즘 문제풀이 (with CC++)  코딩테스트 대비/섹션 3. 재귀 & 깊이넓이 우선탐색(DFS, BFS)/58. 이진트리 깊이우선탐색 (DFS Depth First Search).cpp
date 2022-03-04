#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>	// cin,cout말고 이제 c에서 제공하는 sanf, printf 사용 - 속도가 조금 더 빠름
#include<vector>
#include<algorithm>

using namespace std;

// 이진트리 
//			1
//		  /   \
//		2		3
//	  /   \    /  \
//	4		5 6		7	
// 현재 이진트리는 왼쪽이 부모의 x2 오른쪽이 부모의 x2+1 구조로 생각
// 전위순회 : 부모노드 우선 출력  ( 1 2 4 5 3 6 7 )
// 중위순회 : 부모노드 중간에 출력 ( 4 2 5 1 6 3 7)
// 후위순회 : 부모노드 마지막에 출력 ( 4 5 2 6 7 3 1)

void D(int v)
{
	if (v > 7)
		return;
	else
	{
		printf("%d ", v); // 전위 순회

		D(v * 2); // 왼쪽 자식노드

		printf("%d ", v); // 중위 순회

		D((v * 2) + 1); // 오른쪽 자식 노드

		printf("%d ", v); // 후위 순회 (병합 정렬에 쓰인다)
	}
}

int main()
{
	//freopen("input.txt", "rt", stdin); // input.txt 파일 읽기
	D(1);
	return 0;
}
