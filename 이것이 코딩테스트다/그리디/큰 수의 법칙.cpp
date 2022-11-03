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
    int n, m, k, res = 0;
    cin >> n >> m >> k;
    vector<int> v(n);
    for (int i = 0; i < n; i++)
    {
        cin >> v[i];
    }

    // 가장 큰 수와 그 다음 큰 수를 찾아서 세팅
    sort(v.begin(), v.end());
    int maxNum = v[v.size() - 1];
    int sNum = v[v.size() - 2];

    // 첫 번째로 큰 수 더하기 , 큰수 * k+1번마다 k만큼의 수가 더해지고, 나머지 더하는 공식
    res += maxNum * (m / (k + 1)) * k + (m % (k + 1));
    // 두 번째로 큰 수 더하기, k+1번마다 두번 재 수를 더한다
    res += sNum * (m / (k + 1));

    cout << res;
    return 0;
}