#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>	// cin,cout말고 이제 c에서 제공하는 sanf, printf 사용 - 속도가 조금 더 빠름
#include<vector>
#include<algorithm>

using namespace std;


int main()
{
	//freopen("input.txt", "rt", stdin); // input.txt 파일 읽기
	int size, n, i, j, tmp, idx;
	// size : 메모리 크기, n : 입력되는 총 수 , i :모든 수 돌기 for문, j : 재활용 해서 쓴다, tmp : 현재 작업 숫자, idx : 히트한 인덱스 체크
	scanf("%d %d", &size, & n);

	vector<int> a(size);

	for (i = 0; i < n; i++)
	{
		scanf("%d", &tmp);
		idx = -1;

		for (j = 0; j < size; j++) // 히트인지 아니면 0이 있는지 체크
		{
			if (a[j] == tmp || a[j] == 0)
			{
				if (a[j] == 0) // 현재까지 히트한게 없고 0이 나오면 아직 비어있는 메모리가 있다는 거니까 거기다가 값 넣어줌
					a[j] = tmp;

				idx = j;
				break;
			}
		}

		if (idx == -1) // 0인 값도 없고 맞는 것도 없다면 풀로 찼으니까 맨마지막 값을 지우고 거기다 넣어줌
		{
			idx = size - 1;
			a[idx] = tmp;
		}

		for (j = idx - 1; j >= 0; j--) // 발견 한 값 혹은 넣어준 값을 맨 앞으로 떙긴다.
		{
			a[j + 1] = a[j];
		}
		a[j + 1] = tmp;
	}

	for (j = 0; j < size; j++)
		printf("%d ", a[j]);

	return 0;
}


// 강사 버전
//#define _CRT_SECURE_NO_WARNINGS
//#include<stdio.h>	// cin,cout말고 이제 c에서 제공하는 sanf, printf 사용 - 속도가 조금 더 빠름
//#include<vector>
//#include<algorithm>
//
//using namespace std;
//
//int main()
//{
//	//freopen("input.txt", "rt", stdin); // input.txt 파일 읽기
//	int size, n, i, j, tmp, pos, cnt = 0;
//
//	scanf("%d %d", &size, &n);
//	vector<int> a(size);
//
//	for (i = 0; i < n; i++)
//	{
//		scanf("%d", &tmp);
//		pos = -1;
//
//		for (j = 0; j < size; j++) // 히트인지 미스인지 체크
//		{
//			if (a[j] == tmp)
//			{
//				pos = j;
//				break;
//			}
//		}
//
//		if (pos == -1) // 히트한게 없을경우 
//		{
//			for (j = size - 1; j >= 1; j--) // 모든수를 한칸 씩 뒤로 민다
//				a[j] = a[j - 1];
//		}
//		else
//		{
//			for (j = pos; j >= 1; j--) // 히트했으면 그 인덱스부터 앞의 수들을 한칸씩 뒤로 밀어 주고
//				a[j] = a[j - 1];
//		}
//
//		a[0] = tmp; // 첫번 째 인덱스에 이제 값을 넣어줌
//	}
//
//	for (i = 0; i < size; i++) // 출력
//		printf("%d ", a[i]);
//
//	return 0;
//}
