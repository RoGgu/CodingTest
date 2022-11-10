#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<vector>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    freopen("input.txt", "rt", stdin);
    int N;
    long long sum = 0, min = 1000000001; // 범위가 커서 자로형에 주의해야 한다.
    cin >> N;
    vector<long long> dv(N - 1); // 주유소 간 거리
    vector<long long> cv(N); // 주유소 별 기름 가격

    for (int i = 0; i < N - 1; i++)
    {
        cin >> dv[i];
    }

    for (int i = 0; i < N - 1; i++)
    {
        cin >> cv[i];

        if (cv[i] < min) // 현재 주유소 기름 가격이 지금까지 건너온 주유소 보다 기름가격이 제일 싸면 기름을 넣는다.
        {
            min = cv[i];
            sum += cv[i] * dv[i];
        }
        else
        {
            // 만약 현재 주유소 가격이 더 비쌀경우 저번에 싼 곳 에서 넣은걸로 운전
            sum += min * dv[i];
        }
    }

    cout << sum;
    return 0;
}
