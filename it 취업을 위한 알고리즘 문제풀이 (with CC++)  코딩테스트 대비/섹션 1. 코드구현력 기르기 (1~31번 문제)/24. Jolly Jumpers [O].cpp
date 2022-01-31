#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>	// cin,cout말고 이제 c에서 제공하는 sanf, printf 사용 - 속도가 조금 더 빠름
#include<vector>	// vector 사용을 위해
#include<algorithm>	// exit 프로그램 종료 ,abs 절대값 구하는 함수쓰기위해서 사용을 위해

using namespace std;
int main() {
	//freopen("input.txt", "rt", stdin); // input.txt 파일 읽기
	int i, n, index, pre, now;	// i : for문 카운트, n : 총 배열 숫자의 갯수, index : check인덱스 위치, pre : 배열 전의 수, now : 현재 배열의 수 
	scanf("%d", &n);
	vector<int> checkNum(n);	// 1~n-1까지 숫자 들어가있으면 1로 체크하기위한 배열

	scanf("%d", &pre); // 계산을 위해 첫번째 수는 미리 받아둠
	for (i = 1; i < n; i++)
	{
		scanf("%d", &now);
		index = abs(now - pre);

		if (index > 0 && index < n && checkNum[index] == 0)
		{
			checkNum[index] = 1;
		}
		else // 이미 중복된 수가 있으면 총 갯수가 모자라고 index범위내가 아니면 바로 NO출력하고 종료
		{
			printf("NO");
			exit(0);
		}
		pre = now;
	}

	printf("YES"); // 계속 참되서 다 체크되면 딱 맞는 값들에 들어갔다는거
	return 0;
}
