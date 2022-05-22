#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>
#include<stack>
#include<math.h>
#include <string>

using namespace std;

vector<pair<int, int>> dy(41); // 다이나믹 프로그램으로 기록, 특정 수에 인덱스에, 0 불리는 수 , 1 불리는 수 기록

pair<int, int> fibonacci(int n)
{
    if (dy[n].first != 0 && dy[n].second != 0)
        return dy[n];

    if (n == 0)
    {
        return make_pair(1, 0);
    }
    else if (n == 1)
    {
        return make_pair(0, 1);
    }
    else
    {
        pair<int, int> a = fibonacci(n - 1);
        pair<int, int> b = fibonacci(n - 2);
        dy[n] = make_pair(a.first + b.first, a.second + b.second);
        return dy[n];
    }
}

int main() {
    ios::sync_with_stdio(false);
    freopen("input.txt", "rt", stdin);
    int n, num;
    cin >> n;
    // 0 ,1은 미리 세팅
    dy[0] = make_pair(1, 0);
    dy[1] = make_pair(0, 1);

    for (int i = 0; i < n; i++)
    {
        cin >> num;

        pair<int, int> cnt = fibonacci(num);
        cout << cnt.first << " " << cnt.second << endl; // 0 , 1 카운터 수 출력
    }
    return 0;
}