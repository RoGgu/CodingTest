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

int Gcd(int a, int b)
{
    // 유클리드 호제법으로 GCD 갑 구한다
    while (b > 0)
    {
        int c = a % b;
        a = b;
        b = c;
    }
    return a;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    freopen("input.txt", "rt", stdin);
    int T, N;
    cin >> T;
    vector<int> v(101, 0); // 각 테스틉졀 입력 배열

    for (int t = 0; t < T; t++)
    {
        long long sum = 0; // 모든 쌍의 GCD 합
        cin >> N;

        for (int i = 0; i < N; i++)
        {
            cin >> v[i];
        }

        for (int i = 0; i < N; i++)
        {
            for (int j = i + 1; j < N; j++)
            {
                sum += Gcd(v[i], v[j]);
            }
        }
        cout << sum << endl;
    }

    return 0;
}
