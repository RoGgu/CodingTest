#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>	// cin,cout말고 이제 c에서 제공하는 sanf, printf 사용 - 속도가 조금 더 빠름

int main() {
	//freopen("input.txt", "rt", stdin); // input.txt 파일 읽기
	int i, n = 10, numA = 0, numB = 0;	// i : for문카운트, n : 카드 수, numA : A의 총 승점, numB : B의 총 승점
	char lastWin = 'D';	 // 마지막으로 이긴 사람
	int a[10], b[10]; // 각각의 카드 배열

	for (i = 0; i < n; i++)
		scanf("%d", &a[i]);
	for (i = 0; i < n; i++)
		scanf("%d", &b[i]);

	for (i = 0; i < n; i++)
	{
		if (a[i] == b[i])	// 비기면 1점씩 더해줌
		{
			numA++;
			numB++;
		}
		else if (a[i] > b[i])	// 이긴사람 3점 추가하고 마지막으로 이긴사람을 알기위해 lastWin갱신
		{
			numA += 3;
			lastWin = 'A';
		}
		else if (b[i] > a[i])
		{
			numB += 3;
			lastWin = 'B';
		}
	}

	printf("%d %d\n", numA, numB);

	if (lastWin == 'D') // lastWin이 D면 전체 다 비겼다는 뜻
		printf("D");
	else if (numA == numB)	// 점수 같으면 마지막에 이긴사람이 승자
		printf("%c", lastWin);
	else if (numA > numB)
		printf("A");
	else
		printf("B");

	return 0;
}
