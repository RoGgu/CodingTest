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
    int n, k;
    cin >> n >> k;
    vector<int> w(n + 1);
    vector<int> v(n + 1);
    vector<int> d(k + 1);

    for (int i = 1; i <= n; i++)
        cin >> w[i] >> v[i];

    for (int i = 1; i <= n; i++)
    {
        for (int j = k; j >= 1; j--) // 뒤에서부터 값을 세팅한다/
        {
            if (j - w[i] >= 0) // 현재 i번 물건 넣을 수 있는지 체크
                d[j] = max(d[j], d[j - w[i]] + v[i]); // 넣을 수 있다면 기존에 있는 값이랑(i번쨰 물건 없는 경우)랑 i번째 물건 넣은 경우 비교해서 더 큰거 세팅
        }
    }
    cout << d[k] << endl;


    // 2차원 배열 방식
    //vector<vector<int>> dy(n+1, vector<int>(k+1));
    //for (int i = 1; i <= n; i++)
    //{
    //    for (int j = 1; j <= k; j++)
    //    {
    //        if (j - w[i] >= 0) // 넣을 수 있는 경우 넣을 때랑 안 넣을떄랑 비교해서 세팅
    //        {
    //            dy[i][j] = max(dy[i - 1][j], dy[i - 1][j - w[i]] + v[i]);
    //        }
    //        else // 넣을 수 없는 경우 기존 가치 그대로 세팅
    //            dy[i][j] = dy[i - 1][j];
    //    }
    //}
    //cout << dy[n][k] << endl;

    return 0;
}