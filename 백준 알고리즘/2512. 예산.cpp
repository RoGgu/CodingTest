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
    cin >> n;
    vector<int> v(n, 0);
    for (int i = 0; i < n; i++)
    {
        cin >> v[i];
    }
    cin >> m;

    sort(v.begin(), v.end());

    int s, e, mid, sum = 0;
    s = 0; // 예산 시작 금액은 0원부터 시작
    e = v[n - 1]; // 현재 예산 요청 최대 금액

    while (s <= e)
    {
        mid = (s + e) / 2; // 예산 상한액을 중간 값으로 설정
        sum = 0;

        for (int i = 0; i < n; i++)
        {
            sum += min(v[i], mid); // 중간 값 보다 작은 예산 요청이면 요청만큼 더한다.
        }

        if (sum <= m) // 현재 예싼 상한액을 지정해서 지급한 예산 총 합이  총 예산보다 적을 경우 즉 지급 가능한 경우
        {
            res = mid; // 에싼 상한액 저장
            s = mid + 1; // 최소 금액을 좀더 올린다.
        }
        else // 예산 초과해서 지급 불가능
        {
            e = mid - 1; // 최대 금액을 더 낮춘다.
        }
    }

    cout << res;
    return 0;
}
