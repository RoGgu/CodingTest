#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>	// cin,cout말고 이제 c에서 제공하는 sanf, printf 사용 - 속도가 조금 더 빠름
#include<vector>
#include<algorithm>

using namespace std;

int main() {
	//freopen("input.txt", "rt", stdin); // input.txt 파일 읽기
	int n, m, i, lt = 1, mid, rt, pos, cnt, res = 0;
	scanf("%d %d", &n, &m);
	vector<int> a(n);
	for (i = 0; i < n; i++)
		scanf("%d", &a[i]);

	sort(a.begin(), a.end());

	rt = a[n - 1];
	while (lt <= rt) // 최대 거리 이분검색으로 정해서 말 배치 가능한지 체크
	{
		mid = (lt + rt) / 2;
		cnt = 1; // 배치가능한 말의 수인데 처음 말은 0번째에 넣음
		pos = a[0]; // 말사이의 거리 재기위해 마지막에 넣은 말의 위치
		for (i = 1; i < n; i++)
		{
			if ((a[i] - pos) >= mid) // 기준점보다 거리가 멀면 배치가능한거
			{
				cnt++;
				pos = a[i]; // 말으 여기다 넣고 마지막 말 넣은 위치 저장
			}
		}

		if (cnt >= m) // 배치가능한 말의 수가 실제 말의 수보다 크거나 같으면 최대거리 가능
		{
			lt = mid + 1; // 더 큰 거리 가능한지 체크
			res = mid;
		}
		else
		{
			rt = mid - 1; // 말 배치가 안돼면 최대거리 줄여줌
		}
	}

	printf("%d", res);
	return 0;
}
