#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<queue>
#include<vector>
#include<algorithm>
#include<math.h>
#include<map>

using namespace std;

int main()
{
    freopen("input.txt", "rt", stdin); // input.txt 파일 읽기
    int n;
    cin >> n;
    vector<int> stairs(n);
    vector<int> dy(n);

    for (int i = 0; i < n; i++)
        cin >> stairs[i];

    dy[0] = stairs[0];
    dy[1] = max(stairs[1], stairs[0] + stairs[1]);
    dy[2] = max(stairs[0] + stairs[2], stairs[1] + stairs[2]);

    for (int i = 3; i < n; i++)
    {
        dy[i] = max(stairs[i] + dy[i - 2], stairs[i] + stairs[i - 1] + dy[i - 3]);

    }

    cout << dy[n - 1] << endl;
    return 0;
}

