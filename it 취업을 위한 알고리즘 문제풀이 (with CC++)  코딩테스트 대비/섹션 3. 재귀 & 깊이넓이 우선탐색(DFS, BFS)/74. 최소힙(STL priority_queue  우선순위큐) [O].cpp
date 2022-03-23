#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>	// cin,cout말고 이제 c에서 제공하는 sanf, printf 사용 - 속도가 조금 더 빠름
#include<vector>
#include<queue>
#include<algorithm>

using namespace std;

// priority_queue : 우선순위 큐 사용 (맥스 힙 구조)
// 자식보다 부모가 큰 이진트리 형식으로 구성되어 있다.
// 
// 기존 최대힙 구조에 넣을 떄 -로 부호 바꿔서 넣어서 최소힙 구조로 되도록 한다.


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
				printf("%d\n", -q.top()); // -로 들어가 있으니까 부호 다시 바꿔줌
				q.pop();
			}
		}
		else
			q.push(-tmp); // 부호 바꿔서 최소힙 구조로 되도록 만든다.
	}

	return 0;
}
