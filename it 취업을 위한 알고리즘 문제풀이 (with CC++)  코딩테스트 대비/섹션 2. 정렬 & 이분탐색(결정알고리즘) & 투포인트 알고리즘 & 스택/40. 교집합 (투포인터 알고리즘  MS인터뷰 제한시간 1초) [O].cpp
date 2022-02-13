#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>	// cin,cout말고 이제 c에서 제공하는 sanf, printf 사용 - 속도가 조금 더 빠름
#include<vector>
#include<algorithm>

using namespace std;

int main()
{
	//freopen("input.txt", "rt", stdin); // input.txt 파일 읽기
	int i, j, numA, numB, tmp, pos = 0, posA = 0, posB = 0;

	scanf("%d", &numA);
	vector<int> a(numA);
	for (i = 0; i < numA; i++)
		scanf("%d", &a[i]);

	scanf("%d", &numB);
	vector<int> b(numB);
	for (i = 0; i < numB; i++)
		scanf("%d", &b[i]);



	//삽입 정렬
	//for (i = 1; i < numA; i++)
	//{
	//	tmp = a[i];
	//	for (j = i - 1; j >= 0; j--)
	//	{
	//		if (a[j] > tmp)
	//		{
	//			a[j + 1] = a[j];
	//		}
	//		else
	//			break;
	//	}
	//	a[j + 1] = tmp;
	//}
	//for (i = 1; i < numB; i++)
	//{
	//	tmp = b[i];
	//	for (j = i - 1; j >= 0; j--)
	//	{
	//		if (b[j] > tmp)
	//		{
	//			b[j + 1] = b[j];
	//		}
	//		else
	//			break;
	//	}
	//	b[j + 1] = tmp;
	//}


	// 직접 만든 정렬말고 알고리즘 함수에 있는 기능 씀
	// #include <aglogithm>에 있는 오름차순 정렬
	sort(a.begin(), a.end());
	// #include <aglogithm>에 있는 오름차순 정렬
	sort(b.begin(), b.end());


	// 강사가 만든거 서로 pos를 지정해서 하나씩 돌면서 체크
	while (posA < numA && posB < numB) // 오름 차순 정렬을 하고 한 배열이 끝날때까지 전부 돈다
	{
		if (a[posA] == b[posB]) // 둘의 수가 같을경우 교집합을 표시해주고 서로 pos 인덱스를 증가시켜준다.
		{
			printf("%d", a[posA]);
			posA++;
			posB++;
		}
		else if (a[posA] < b[posB])	// 오름차순 정렬을 했기 떄문에 b보다 작다면 b한테는 없는 숫자 이기 때문에 작은 수를 증가
			posA++;
		else if (a[posA] > b[posB])	// 위와 마찬가지
			posB++;
	}

	// 내가 만든거 총 배열의 수가 작은 한 배열이 끝날떄가지 도는데
	// 오름 차순 정렬 이기 떄문에 현재 기준 수랑 다른게 큰 수나오면 뒤에 수는 더 큰 수이기 때문에 볼 필요없어서 패스
	// 근데 다음 수 검사할때 이미 전 수에서 체크한 앞에 배열수들은 자기보다 다 작은 수니까 검사 안하고 패스한 인덱스 부터 시작해서 속도 빠르게 함
	//if (numA < numB)
	//{
	//	for (i = 0; i < numA; i++)
	//	{
	//		bool isHave = false;

	//		for (j = pos; j < numB; j++)
	//		{
	//			if (b[j] > a[i])
	//				break;
	//			if (a[i] == b[j])
	//			{
	//				isHave = true;
	//				break;
	//			}
	//		}
	//		pos = j;
	//		if (isHave == true)
	//		{
	//			printf("%d ", a[i]);
	//		}
	//	}
	//}
	//else
	//{
	//	for (i = 0; i < numB; i++)
	//	{
	//		bool isHave = false;

	//		for (j = pos; j < numA; j++)
	//		{
	//			if (a[j] > b[i])
	//				break;

	//			if (b[i] == a[j])
	//			{
	//				isHave = true;
	//				break;
	//			}
	//		}
	//		pos = j;
	//		if (isHave == true)
	//		{
	//			printf("%d ", b[i]);
	//		}
	//	}
	//}

	return 0;
}
