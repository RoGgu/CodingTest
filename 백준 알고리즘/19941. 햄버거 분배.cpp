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
    int n, k, res = 0;
    cin >> n >> k;

    vector<char>v(n, 0); // H, P 햄버거 사람 담는 배열
    vector<int>ch(n, 0); // H 햄버거 먹었는지 체크 배열 1이면 이미 먹은 햄버거
    for (int i = 0; i < n; i++)
    {
        cin >> v[i];
    }

    for (int i = 0; i < n; i++)
    {
        if (v[i] == 'P') // 사람일 경우 먹을 수 있는 햄버거 있는지 체크
        {
            for (int j = i - k; j < i + k + 1; j++) // K 거리안에 먹을 수 있는 햄버거가 있는지 체크한다.
            {
                if (j >= 0 && j < n)
                {
                    if (ch[j] == 0 && v[j] == 'H') // 먹을 수 있는 거리에 안 먹은 햄버거 있으면 먹고 개 수 증가
                    {
                        ch[j] = 1;
                        res++;
                        break;
                    }
                }
            }
        }
    }

    cout << res;
    return 0;
}
