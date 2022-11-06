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

const int maxNum = 10001; // 입력 최대 수
int arr[maxNum]; // 소수는 0, 아니면 1

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    freopen("input.txt", "rt", stdin);
    int T, n;
    cin >> T;

    arr[0] = 1;
    arr[1] = 1;

    // 에라토스테네스의 체로 소수 체크
    for (int i = 2; i <= sqrt(maxNum); i++)
    {
        if (arr[i] == 1)
            continue;

        for (int j = 2 * i; j <= maxNum; j += i)
        {
            arr[j] = 1;
        }
    }

    for (int i = 0; i < T; i++)
    {
        cin >> n;
        int tmp = n / 2; // 중간 값부터 체크 한다

        if (arr[tmp] == 0) // 만약 중간 값이 소수이면 바로 같은 소수 출력, 둘의 차이가 0이기 떄문이다
        {
            cout << tmp << " " << tmp << "\n";
            continue;
        }

        // 하나 씩 증가시켜 가면서 소수 짝 찾아서 출력
        for (int j = tmp + 1; j < n; j++)
        {
            if (arr[j] == 0 && arr[n - j] == 0)
            {
                cout << n - j << " " << j << "\n";
                break;
            }
        }
    }

    return 0;
}
