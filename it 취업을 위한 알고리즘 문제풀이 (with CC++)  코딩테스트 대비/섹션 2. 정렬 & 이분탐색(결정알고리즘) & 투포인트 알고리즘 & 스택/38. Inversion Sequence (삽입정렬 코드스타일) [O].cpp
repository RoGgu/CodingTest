#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>	// cin,cout말고 이제 c에서 제공하는 sanf, printf 사용 - 속도가 조금 더 빠름
#include<vector>
#include<algorithm>

using namespace std;

int main()
{
	// 강사 풀이보고 푼거
	//freopen("input.txt", "rt", stdin); // input.txt 파일 읽기
	int n, i, j, pos;
	// n: 입력 수, i : 큰수부터 차례대로 돌면서 입력, j : 뒤에 큰수 땡겨야하는 for문, pos : 떙겨지는 index
	vector<int> is(n + 1); // inversion Sequence 배열
	vector<int> os(n + 1); // is를 통해 구해진 원래 수의 배열 (정답)
	scanf("%d", &n);


	for (i = 1; i <= n; i++)
		scanf("%d", &is[i]);

	// 뒤에서부터 큰수 넣으면서 돈다.
	// 만약 자기앞에 큰 숫자가 필요할 경우 뒤에있는 큰숫자를 앞으로 떙기고 그위치에 자기숫자를 넣는다.
	for (i = n; i >= 1; i--)
	{
		pos = i;
		for (j = 1; j <= is[i]; i++) // 앞에 큰 수가 있어야 하는 개수만큼 돈다
		{
			os[pos] = os[pos + 1]; // 뒤로가면서 뒤에꺼 앞으로 떙겨준다
			pos++; // 뒤로 한칸씩 이동
		}
		os[pos] = i; // 이제 다 떙겨주고나서 알맞는 위치에 자기 수를 넣어줌
	}

	for (i = 0; i < n; i++)
		printf("%d ", os[i]);

	return 0;


	//// 내가 푼거 삽입 정렬은 안 썻다.
	////freopen("input.txt", "rt", stdin); // input.txt 파일 읽기
	//int n, i, j, tmp, cnt = 0;
	//int a[101] = {};
	//scanf("%d", &n);

	//// 앞에서부터 자기보다 큰 숫자가 올 경우를 생각하고 1부터 넣어준다
	//for (i = 1; i <= n; i++)
	//{
	//	scanf("%d", &tmp);
	//	cnt = tmp;
	//	for (j = 0; j < n; j++)
	//	{
	//		if (j == cnt && a[j] == 0)	// 자기보다 큰 숫자가 와야하는 조건이맞고 해당 index가 0이면 넣어줌
	//		{
	//			a[j] = i;
	//			break;;
	//		}
	//		else if (a[j] != 0 && a[j] < i) // 이미 다른수가 들어가 있는데 자기보다 작으면 더 한칸 더 뒤로가야해서 가야할 카운트 증가
	//		{
	//			cnt++;
	//		}
	//	}
	//}

	//for (i = 0; i < n; i++)
	//{
	//	printf("%d ", a[i]);
	//}

	//return 0;
}
