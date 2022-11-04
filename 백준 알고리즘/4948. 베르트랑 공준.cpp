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

const int maxNum = 246913; // 입력 최대 수
int arr[maxNum]; // 소수는 0, 아니면 1

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    freopen("input.txt", "rt", stdin);
    int n;
    int cnt = 0;

    // 에스토스테네스의 체로 최대 수까지 소수 뺴곤 다 1으로 변경
    for (int i = 2; i <= sqrt(maxNum); i++)
    {
        if (arr[i] == 1)
            continue;

        for (int j = 2 * i; j <= maxNum; j += i)
        {
            arr[j] = 1;
        }
    }

    while (true)
    {
        cnt = 0;
        cin >> n;
        if (n == 0) // n이 0이면 종료
            break;

        // n+1 부터 2n 까지의 소수 수 체크
        for (int i = n + 1; i <= n * 2; i++)
        {
            if (arr[i] == 0)
                cnt++;
        }

        cout << cnt << "\n";
    }

    return 0;
}
