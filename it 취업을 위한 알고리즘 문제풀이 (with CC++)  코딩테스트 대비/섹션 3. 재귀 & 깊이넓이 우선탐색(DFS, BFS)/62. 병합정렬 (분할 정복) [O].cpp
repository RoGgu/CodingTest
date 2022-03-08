#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>	// cin,cout말고 이제 c에서 제공하는 sanf, printf 사용 - 속도가 조금 더 빠름
#include<vector>
#include<algorithm>

using namespace std;

int arr[100];
int tmp[100];

void divide(int lt, int rt)
{
	int mid;
	int p1, p2, p3;
	if (lt < rt)
	{
		mid = (lt + rt) / 2;
		divide(lt, mid); // lt~mid까지 정렬
		divide(mid + 1, rt); // mid+1 ~ rt 까지 정렬

		p1 = lt; // 왼쪽 정렬된 배열 시작 위치
		p2 = mid + 1; // 오른쪽 정렬된 배열 시작위치
		p3 = lt; // 임시배열 변수에 넣는 위치

		// 서로 각자 정렬된 두가지 배열이 있다.
		// arr1 [lt ~mid];
		// arr2 [mid +1 ~ rt]
		// 이렇게 정렬된 두 가지 배열을 서로 다시 병합정렬 한다는 개념

		while (p1 <= mid && p2 <= rt) // 각각의 시작 포인트부터 작은수를 넣는다.
		{
			if (arr[p1] <= arr[p2])
				tmp[p3++] = arr[p1++];
			else
				tmp[p3++] = arr[p2++];
		}

		// 한쪽이 끝날때 까지 헀으니 남은쪽을 다 뒤에 넣어줌
		while (p1 <= mid)
			tmp[p3++] = arr[p1++];

		while (p2 <= rt)
			tmp[p3++] = arr[p2++];

		// 이제 tmp에 임시 배열에 정렬해서 넣은걸 진짜 배열값에 넣어주면 lt ~ rt까지 정렬
		for (int i = lt; i <= rt; i++)
		{
			arr[i] = tmp[i];
		}
	}
}


int main()
{
	//freopen("input.txt", "rt", stdin); // input.txt 파일 읽기
	int n;
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
		scanf("%d", &arr[i]);

	divide(0, n - 1);

	for (int i = 0; i < n; i++)
		printf("%d ", arr[i]);


	return 0;
}
