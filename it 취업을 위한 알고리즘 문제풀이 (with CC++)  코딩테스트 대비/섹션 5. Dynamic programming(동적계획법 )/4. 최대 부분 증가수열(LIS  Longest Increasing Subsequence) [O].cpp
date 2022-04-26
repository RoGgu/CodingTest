#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>	// cin,cout말고 이제 c에서 제공하는 sanf, printf 사용 - 속도가 조금 더 빠름
#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
#include<cstdlib>

using namespace std;

// 최대 부분 증가수열(LIS :Longest Increasing Subsequence)
// 0부터 배열을 돌면서 현재 배열을 마지막 인덱스라고 생가갛고 최대 증가 수를 dy에 저장한다.
// 그래서 그 다음 배열인덱스를 볼떄 자기보다 앞에있는 인덱스중 작은애들을 다 돌면서 dy값이 가장 큰애에 +1을해서 자기 dy값에 넣는다.
// 이제 dy배열중 가장 큰 값이 최대 증가 수 이다.


int main()
{
	//freopen("input.txt", "rt", stdin); // input.txt 파일 읽기
	int n, tmp, cnt = 0;
	int max = INT32_MIN;
	cin >> n;
	vector<int> arr(n); // 배열 저장 
	vector<int> dy(n, 1); // 다이나믹 으로 현재 배열까지의 최대 증가 수 저장해둔다

	for (int i = 0; i < n; i++)
	{
		cin >> tmp;
		arr[i] = tmp;
	}

	for (int i = 1; i < n; i++)
	{
		max = 0; // 처음 max 초기화
		for (int j = i - 1; j > 0; j--)
		{
			if (arr[j] < arr[i]) // 자기보다 작아야 한다.
			{
				if (dy[j] > max) // 현재까지 자기보다 작은애들의 최대 증가 수 중 가장 긴 애를 찾는다
					max = dy[j];
			}
		}
		dy[i] = max + 1; // 자신의 dy 값은 자기 밑에있는애들 중 가장 긴 값 +1(이제 자기 포함하니까)
		if (dy[i] > cnt)
			cnt = dy[i];
	}

	cout << cnt << endl; // 최대 증가 수열의 길이 출력
	return 0;
}
