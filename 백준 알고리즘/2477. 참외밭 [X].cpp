#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<string>
#include<vector>
#include<stack>
#include<queue>
#include<algorithm>
#include<cmath>
#include<map>
using namespace std;

int N;
int arr[6][2];  // 주어지는 방향, 길이쌍
int cnt[5]; // 방향 별 등장 횟수 저장

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    freopen("input.txt", "rt", stdin);
    int s = 1; // 작은 사각형의 넓이
    int b = 1; // 큰 사각형의 넓이

    // 입력 받기
    cin >> N;
    for (int i = 0; i < 6; i++)
    {
        cin >> arr[i][0] >> arr[i][1];
        cnt[arr[i][0]]++;
    }

    for (int i = 0; i < 6; i++)
    {

        if (cnt[arr[i][0]] == 1)
        {
            // 한 번씩 등장하는 방향이다
            b *= arr[i][1]; // 큰 사각형의 너비/높이이다
            continue;
        }

        // 시작점이 다르기 떄문에 modulo (나머지)연산 사용
        int ni = (i + 1) % 6;
        int nni = (i + 2) % 6;
        // 현재(I)랑 다다음거(nni)랑 같으면 그 사이에 있는 것(ni)이 작은 사각형의 너비/높이이다
        if (arr[i][0] == arr[nni][0])
        {
            s *= arr[ni][1];
        }
    }

    // 큰 사각형의 넓이 - 작은 사각형의 넓이로 총 육각형의 넓이 구하고 평당 옥수수 수 곱한다
    printf("%d", (b - s) * N);
    return 0;
}
