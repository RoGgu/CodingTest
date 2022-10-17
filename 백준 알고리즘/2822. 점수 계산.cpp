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

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    freopen("input.txt", "rt", stdin);
    int sum = 0;
    vector<pair<int, int>> vp(8);
    vector<int> res;
    for (int i = 0; i < 8; i++)
    {
        cin >> vp[i].first;
        vp[i].second = i + 1;
    }

    sort(vp.begin(), vp.end()); // 점수로 오름차순 정렬
    for (int i = 0; i < 5; i++) // 상위 5개 점수 더하고 번호 세팅
    {
        sum += vp[7 - i].first;
        res.push_back(vp[7 - i].second);
    }

    cout << sum << "\n"; // 상위 5개점수 합 출력

    sort(res.begin(), res.end()); // 상위 5개 문제번호 오름차순 정렬
    for (int i = 0; i < 5; i++)
    {
        cout << res[i] << " "; // 문제 번호 출력
    }

    return 0;
}
