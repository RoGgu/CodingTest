#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>	// cin,cout말고 이제 c에서 제공하는 sanf, printf 사용 - 속도가 조금 더 빠름
#include<vector>
#include<algorithm>

using namespace std;

int main()
{
	//freopen("input.txt", "rt", stdin); // input.txt 파일 읽기
	char a[10]; // 입력 값
	int i, c = 0, h = 0, pos;	// i : for문 카운트  c :탄소 개수, h : 수소 개수, pos : 탄소 수소 인덱스 체크를위한 수
	scanf("%s", &a);

	if (a[1] == 'H')	// 두번째바로 H면 C는 숫자가 없다는 거니까 1
	{
		c = 1;
		pos = 1;
	}
	else
	{
		for (i = 1; a[i] != 'H'; i++) // 탄소의 개수 카운트
		{
			c = c * 10 + (a[i] - 48);
		}
		pos = i;
	}

	if (a[pos + 1] == '\0')	// 수소바로 뒤에 끝나면 수소개수는 1
		h = 1;
	else
	{
		for (i = pos + 1; a[i] != '\0'; i++)
		{
			h = h * 10 + (a[i] - 48);
		}
	}

	printf("%d", (c * 12 + h));
	return 0;
}



//int main() {
//	//freopen("input.txt", "rt", stdin); // input.txt 파일 읽기
//	int index = 1, num = 0,res = 0;
//	char a[10];
//	char prev, cur;
//
//	scanf("%s", &a);
//
//	prev = a[0];
//	while (true)
//	{
//		cur = a[index];
//		if (cur == '\0')
//			break;
//
//		if (cur >= 65 && cur <= 90)
//		{
//			if (num == 0)
//				num = 1;
//
//			if (prev == 67)
//				res = res + (12 * num);
//			else
//				res++;
//
//			prev = cur;
//			num = 0;
//		}
//		else
//			num = num * 10 + (cur - 48);
//
//		index++;
//	}
//
//	if (num == 0)
//		num = 1;
//
//	if (prev == 67)
//		res = res + (12 * num);
//	else
//		res = res + num;
//
//	printf("%d", res);
//	return 0;
//}
