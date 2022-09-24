#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<string>
#include<vector>
#include<stack>
#include<queue>
#include<algorithm>
#include<cmath>
#include<map>
using namespace std;

bool Compare(const pair<int, int>& a, const pair<int, int> b)
{
    // 끝나는 시간 우선으로 정렬하는데 같으면 시작시간 체크해서 오름차순 정렬
    if (a.second == b.second)
        return a.first < b.first;
    else
        return a.second < b.second;

}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n, maxTime = 0, res = 0;
    cin >> n;
    vector<pair<int, int>> vp(n);
    for (int i = 0; i < n; i++)
    {
        cin >> vp[i].first;
        cin >> vp[i].second;
    }

    sort(vp.begin(), vp.end(), Compare);
    // 첫 회의 종료시간 세팅
    int time = vp[0].second;
    res = 1;

    for (int i = 1; i < n; i++)
    {
        // 새 회의 시작시간이 이전 회의 종료시간 보다 같거나 크면 회의 가능
        if (vp[i].first >= time)
        {
            ++res;
            time = vp[i].second;
        }
    }

    cout << res;
    return 0;
}