#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    freopen("input.txt", "rt", stdin);
    int N;
    long long res = 0;
    cin >> N;
    vector<int> v(N);

    for (int i = 0; i < N; i++)
    {
        cin >> v[i];
    }

    sort(v.begin(), v.end()); // 오름차순으로 정렬

    for (int i = 1; i <= N; i++)
    {
        // 예상 등수 1등에 가까운 사람부터 1등씩줘서 실제 등수 차이를 최소로 한다
        res += abs(v[i - 1] - i);
    }

    cout << res;
    return 0;
}
