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
    int n, cnt = 0;
    cin >> n;

    for (int i = 0; i < n; i++)
    {
        int num;
        cin >> num;
        if (num == 1)
            continue;
        cnt += 1;
        for (int i = 2; i * i <= num; i++)
        {
            if (num % i == 0)
            {
                cnt -= 1;
                break;
            }
        }
    }

    cout << cnt << "\n";
    return 0;
}

