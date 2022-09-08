#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<string>
#include<vector>
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
    int N;
    cin >> N;

    int res = 0;
    int fiveN = 5; // 현재 5의 제곱 체크 수

    while (N >= fiveN)
    {
        res += (N / fiveN);
        fiveN = fiveN * 5; // 5를 곱해줘서 다음 5의 제곱수로 체크
    }

    cout << res;
    return 0;
}
