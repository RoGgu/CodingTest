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
    int T, N;
    cin >> T;
    vector<long long> v = { 0, 1, 1, 1, 2, 2, 3, 4, 5, 7, 9 }; // 수가 커짐에 따라 int범위 넘어가서 long long 선언
    v.resize(101);


    for (int i = 11; i <= 100; i++) // 최대 입력수가 100이라 100까지 미리 구해준다.
    {
        v[i] = v[i - 1] + v[i - 5]; // P(N)의 갑을 구하는 규칙
    }

    for (int i = 0; i < T; i++)
    {
        cin >> N;

        cout << v[N] << "\n";
    }

    return 0;
}
