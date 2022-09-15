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
    int N, M, res;
    cin >> N >> M;

    res = (N - 1) + N * (M - 1); // 가로를 1의 크기로 자르기 위해 가로로 (N-1)만큼 자르고 세로를 1로 만들기위해 (M-1)만큼 잘라는데 가로로 자른 초콜릿 조각 만큼 잘라준다.
    //res = (N * M) - 1; // 수학 공식을 풀어쓰면 이렇게도 답이 나온다.

    cout << res;
    return 0;
}