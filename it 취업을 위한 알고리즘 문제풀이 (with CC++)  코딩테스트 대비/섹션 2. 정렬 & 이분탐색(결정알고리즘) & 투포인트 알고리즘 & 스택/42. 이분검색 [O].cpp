#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>	// cin,cout말고 이제 c에서 제공하는 sanf, printf 사용 - 속도가 조금 더 빠름
#include<vector>
#include<algorithm>

using namespace std;

// 이분 검색 
// 일단 오름차순으로 정렬한다
// lt는 왼쪽끝, rt는 오른쪽 끝으로 초기화
// mid = (lt + rt)/ 2 중간값 mid
// lt(0)		  mid(3)		      rt(7)
// [12] [23] [32] [56] [65] [81] [87] [99]
// 찾아야 하는수 key
// 1) key == mid 인지 일단 검사
// 2-1) mid 값이 찾고자 하는 수보다 크다면 rt = mid-1 을 넣어줌
// lt(0) mid(1) rt(2)
// [12]  [23]	[32] [56] [65] [81] [87] [99]
// 2-2) mid 값이 찾고자 하는 수보다 작을 경우 lt = mid+1 을 넣어줌
//					   lt(4) mid(5)     rt(7)
// [12] [23] [32] [56] [65]  [81]  [87] [99]

// 3) 2번 계속 반복
// mid랑 key값이랑 같아질떄까지

int main()
{
	//freopen("input.txt", "rt", stdin); // input.txt 파일 읽기
	int n, key, i, lt, mid, rt;

	scanf("%d %d", &n, &key);
	vector<int> a(n);
	for (i = 0; i < n; i++)
		scanf("%d", &a[i]);

	// printf("%d", *(a.end()-1));// 그래서 마지막 배열 수 가르킬려면 end()-1해줘야함
	sort(a.begin(), a.end()); // end()는 마지막 배열을 가르키는게 아니라 마지막 배열의 다음꺼를 가르킴
	lt = 0;
	rt = n - 1;
	
	while (lt <= rt)// 자료가 없을경우 교차되어버림
	{
		mid = (lt + rt) / 2;
		if (a[mid] == key) // 자료 찾으면 출력하고 종료
		{
			printf("%d", (mid + 1));
			return 0;
		}

		else if (a[mid] > key)
		{
			rt = mid - 1;
		}
		else
			lt = mid + 1;
	}

	return 0;
}
