#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<vector>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    freopen("input.txt", "rt", stdin);
    int n, k, cnt = 0;
    vector<int> coin;
    cin >> n >> k;
    for (int i = 0; i < n; i++) // 동전 세팅
    {
        int tmp;
        cin >> tmp;
        coin.push_back(tmp);
    }

    for (int i = n - 1; i >= 0; i--)
    {
        while (k >= coin[i]) // 현재 동전으로 계산 가능하면 동전 카운트하고 값 뺀다.
        {
            k -= coin[i];
            cnt++;
        }
    }

    cout << cnt << endl;

    return 0;
}