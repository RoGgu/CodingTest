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

    sort(v.begin(), v.end()); // 오름차순 정렬

    // 끝에서 부텅 체크하면서 가격 큰거부터 3묶음씩 묶는다
    int cnt = 1;
    for (int i = v.size() - 1; i >= 0; i--)
    {
        if (cnt == 3) // 3번쨰 묶음은 무료라서 가격에 추가하지 않는다
        {
            cnt = 1;
            continue;
        }
        else
        {
            cnt++;
            res += v[i];
        }
    }

    cout << res;
    return 0;
}
