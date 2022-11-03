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
    int n, nums = 0, res = 0;
    cin >> n;
    vector<int> v(n);
    for (int i = 0; i < n; i++)
        cin >> v[i];

    // 공포감 오름차순으로 정렬
    sort(v.begin(), v.end());

    for (int i = 0; i < n; i++)
    {
        // 현재 파티에 모험가 추가
        nums += 1;

        // 현재 파티의 수가 공포감보다 크거나 같으면 파티 결성된거 출정 가능
        if (nums >= v[i])
        {
            res += 1;
            nums = 0; // 현재 파티 나갔으니 새로운 파티 생성
        }
    }

    cout << res;
    return 0;
}