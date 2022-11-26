#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

bool cmp(pair<int, int> x, pair<int, int> y)
{
    // 시작 시간이 같다면 소요시간이 더 짧은게 앞으로 오도록 한다
    if (x.first == y.first)
    {
        return x.second < y.second;
    }
    else
    {
        return x.first < y.first; // 그 외엔 시작시간이 짧은게 먼저 오도록
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    freopen("input.txt", "rt", stdin);
    int n;
    int cnt = 0;
    cin >> n;
    vector<pair<int, int>> arr;

    for (int i = 0; i < n; i++)
    {
        int start, tmp;
        cin >> start >> tmp;
        pair<int, int> tmpPair = make_pair(start, tmp);
        arr.push_back(tmpPair);
    }

    // 비교함수 기준으로 정렬
    sort(arr.begin(), arr.end(), cmp);

    for (auto now : arr)
    {
        // 현재 시간이 first보다 작다면 first로 갱신
        if (cnt < now.first)
        {
            cnt = now.first;
        }
        // 소요시간인 second를 더해준다
        cnt += now.second;
    }

    cout << cnt;
    return 0;
}
