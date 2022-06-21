#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<string.h>
#include<vector>
#include<queue>
#include <unordered_map>
#include<algorithm>
using namespace std;


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    freopen("input.txt", "rt", stdin);

    int m, n;
    cin >> m >> n;

    vector<int> arr(n + 1, 0);

    for (int i = 2; i <= n; i++)
    {
        arr[i] = i;
    }

    // 에라토스테네스의 체 이용해서 풀이
    for (int i = 2; i * i <= n; i++)
    {
        if (arr[i] == 0)
            continue;
        for (int j = 2 * i; j <= n; j += i)
        {
            if (arr[j] == 0)
                continue;
            else
                arr[j] = 0;
        }
    }

    for (int i = m; i <= n; i++)
    {
        if (arr[i] != 0)
            cout << arr[i] << "\n";
    }
    return 0;
    return 0;
}