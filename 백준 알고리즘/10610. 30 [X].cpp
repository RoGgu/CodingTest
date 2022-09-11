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
    string s;
    cin >> s;
    vector<int> v(s.size());
    int sum = 0;
    for (int i = 0; i < s.size(); i++)
    {
        v[i] = s[i] - '0'; // char 을 int로 값 세팅해서 넣어준다.
        sum += v[i];
    }

    sort(v.begin(), v.end());

    if (sum % 3 != 0 || v[0] != 0) // 제일 작은 수 가 0이지 않고 총 합이 3으로 나누어 떨어지지 않으면 30의 곱이 아니다.
        cout << -1;
    else
    {
        for (int i = v.size() - 1; i >= 0; i--) // 30의 곱이니 큰 수부터 출력
        {
            cout << v[i];
        }
    }


    return 0;
}
