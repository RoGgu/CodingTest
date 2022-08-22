#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<string>
#include<vector>
#include<queue>
#include<algorithm>
#include<cmath>
#include<map>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    freopen("input.txt", "rt", stdin);
    int n, m, res = 0;
    int start = 0, end = 0, sum = 0;
    cin >> n >> m;
    vector<int> v(n + 1, 0); // 마지막 인덱스는 체크할 때 더미용

    for (int i = 0; i < n; i++)
    {
        cin >> v[i];
    }

    sum = v[0];
    while (start <= end && end < n)
    {
        if (sum < m)
        {
            ++end;
            sum += v[end];
        }
        else if (sum == m)
        {
            res++;
            end++;
            sum += v[end];
        }
        else if (sum > m)
        {
            sum -= v[start];
            start++;

            if (start >= end) // 시작 인덱스가 끝 인덱스보다 크거나 같아지면 현재 start 인덱스부터 다시 시작
            {
                end = start;
                sum = v[start];
            }
        }

    }

    cout << res;
    return 0;
}
