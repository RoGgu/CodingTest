#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<string.h>
#include<vector>
#include<queue>
#include<algorithm>
using namespace std;


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    freopen("input.txt", "rt", stdin);
    int n;
    cin >> n;
    vector<vector<int>> triangle(n);
    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j <= i; ++j)
        {
            int num;
            cin >> num;
            triangle[i].push_back(num);
        }
    }

    // 바텀업 방식 풀이
    vector<int> v = triangle[triangle.size() - 1]; // 현재 높이에 각 인덱스별 최대값을 세팅한다.
    for (int i = triangle.size() - 2; i >= 0; --i)
    {
        for (int j = 0; j <= i; ++j)
        {
            v[j] = triangle[i][j] + max(v[j], v[j + 1]);
        }
    }

    cout << v[0] << endl;
    return 0;
}