#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<string>
#include<vector>
#include<queue>
#include<algorithm>
#include<cmath>
#include<map>
using namespace std;

bool cmp(int a, int b)
{
    return a > b;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    freopen("input.txt", "rt", stdin);
    int n;
    cin >> n;
    vector<int> v;
    while (n > 0) // 한 자리 씩 배열에 세팅
    {
        v.push_back(n % 10);
        n = n / 10;
    }

    sort(v.begin(), v.end(), cmp); // 내림차순 조건 함수로 내림차순 정렬

    for (int i = 0; i < v.size(); i++)
    {
        cout << v[i];
    }

    return 0;
}
