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
    ios::sync_with_stdio(false);
    int n;
    cin >> n;
    int res = 0;
    vector<int> dy;

    // 피보나치로 푸는 문제
    dy.push_back(1);
    dy.push_back(2);

    for (int i = 2; i < n; i++)
    {
        dy.push_back((dy[i - 1] + dy[i - 2]) % 10007); // 10007로 나눠준 값을 가져야한다.
    }

    cout << dy[n - 1] << endl;
    return 0;
}

