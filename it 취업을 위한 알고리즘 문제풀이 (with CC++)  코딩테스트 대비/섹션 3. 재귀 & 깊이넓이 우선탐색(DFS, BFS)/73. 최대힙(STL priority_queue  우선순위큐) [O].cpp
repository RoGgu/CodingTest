#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>	// cin,cout말고 이제 c에서 제공하는 sanf, printf 사용 - 속도가 조금 더 빠름
#include<vector>
#include<queue>
#include<algorithm>

using namespace std;

// priority_queue : 우선순위 큐 사용 (맥스 힙 구조)
// 자식보다 부모가 큰 이진트리 형식으로 구성되어 있다.
// 
// 새로 push할때마다 빈자리에 먼저 넣고 그다음 자기 부모랑 비교해서
// 새로 넣은값이 더 클경우 자리 바꾸는걸 반복해서
// 제일 큰 수가 최대 루트값이 된다.
// top와 pop을 하면 최대 루트값이 나온다
// pop을 할 시 최대 루트 빼고 마지막 노드 값을 최대 루트값으로 넣고 삭제하고
// 밑에 다운힙 하면서 자기보다 밑에 자식이 크다면 바까주는거 반복해서
// 다시 최대 큰 값이 최대루트값이 된다.


int main()
{
	//freopen("input.txt", "rt", stdin); // input.txt 파일 읽기
	int tmp;
	priority_queue<int> q; // 우선순위 큐 생성

	while (true)
	{
		scanf("%d", &tmp);
		if (tmp == -1) // -1이면 프로그램 종료
			break;
		else if (tmp == 0) // 0일 경우 현재 최대 힙 출력하고 빼줌
		{
			if (q.empty() == true) // 비어있으면 -1 출력
				printf("-1");
			else
			{
				printf("%d\n", q.top()); // top : 제일 큰 값 루트값
				q.pop();
			}
		}
		else
			q.push(tmp); // 아니면 새로 값 넣어줌
	}

	return 0;
}
