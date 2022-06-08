#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<string.h>
#include<vector>
#include<algorithm>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    freopen("input.txt", "rt", stdin);
    int n, tmp, res = 1;
    cin >> n;

    tmp = 1;
    while (tmp < n)
    {
        tmp += 6 * res;
        res++;
    }

    cout << res << endl;
    return 0;
}