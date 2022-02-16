#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>	// cin,cout말고 이제 c에서 제공하는 sanf, printf 사용 - 속도가 조금 더 빠름
#include<vector>
#include<algorithm>

using namespace std;


int main() {
	//freopen("input.txt", "rt", stdin); // input.txt 파일 읽기
	int n, m, i, lt = 1, rt = 0, mid, res, cnt = 0, tmp = 0, max = -2147000000;
	scanf("%d %d", &n, &m);
	vector<int> a(n);
	for (i = 0; i < n; i++)
	{
		scanf("%d", &a[i]);
		rt += a[i];	// 최대 메모리 값은 다 더한거니 최댓값 설정
		if (max < a[i])
			max = a[i];
	}

	while (lt <= rt) // 교차하는 순간 이분검색 끝
	{
		mid = (lt + rt) / 2; // 미들 값 설정 - 앨범 사이즈
		cnt = 1;
		tmp = 0;

		for (i = 0; i < n; i++) // 곡 전부 돌면서 메모리 제한에 몇개에 DVD 필요한지 체크
		{
			if (tmp + a[i] > mid) // 메모리 제한 초과하면 새로운 DVD추기
			{
				tmp = a[i];
				cnt++;
			}
			else
				tmp += a[i]; // 아닐경우 DVD에 메모리 추가
		}

		if (mid >= max && cnt <= m) // DVD메모리는 최소 뮤직비디오 용량보다 크거나같아야한다 && DVD 개수제한 안에 들면 메모리 넣어주고 아래에 있는 메모리사이즈 다시 체크
		{
			res = mid;
			rt = mid - 1;
		}
		else
			lt = mid + 1;
	}

	printf("%d", res);
	return 0;
}
