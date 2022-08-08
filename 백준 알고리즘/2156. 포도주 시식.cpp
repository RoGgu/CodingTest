#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<queue>
#include<vector>
#include<algorithm>
#include<math.h>
#include<map>
#include<set>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    freopen("input.txt", "rt", stdin); // input.txt 파일 읽기
    int n;
    cin >> n;
    vector<int> arr(n + 1, 0);
    vector<int> dy(n + 1, 0);
    for (int i = 1; i <= n; i++)
    {
        cin >> arr[i];
    }

    dy[1] = arr[1];
    dy[2] = arr[1] + arr[2];

    for (int i = 3; i <= n; i++)
    {
        // i번째 잔의 최대 마신 값 세팅 할 수 있는 3가지 경우 비교
        int n1 = dy[i - 3] + arr[i - 1] + arr[i];
        int n2 = dy[i - 2] + arr[i];
        int n3 = dy[i - 1];

        dy[i] = max(n1, max(n2, n3)); // 세 개의 경우에서 가장 큰 값 세팅
    }

    cout << max(dy[n], dy[n - 1]); // n번째를 마시지 않은 경우가 있어서 n-1랑 비교해서 큰 값 표시

    return 0;
}

