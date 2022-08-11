#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<string>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    freopen("input.txt", "rt", stdin);
    int n, tmp0, tmp2;
    int input[3];
    int maxDy[3] = { 0,0,0 };
    int minDy[3] = { 0,0,0 };
    cin >> n;

    // 처음 입력 값은 그대로라 세팅
    for (int i = 0; i < 3; i++)
    {
        cin >> maxDy[i];
        minDy[i] = maxDy[i];
    }

    // 한 줄 마다 최대값 최소값 세팅하는 형식으로 구한다.
    // 인접 한 곳은 갈 수 있으니 위에서 내려올 때 현재 세팅된 수에서 큰 수(maxDy세팅) 혹은 작은 수(minDy) 가 내려와서 현재 입력 값 더해서 세팅하는 형식
    for (int i = 1; i < n; i++)
    {
        cin >> input[0] >> input[1] >> input[2];
        // 최대값 구하기
        tmp0 = maxDy[0];
        tmp2 = maxDy[2];
        maxDy[0] = max(maxDy[0], maxDy[1]) + input[0];
        maxDy[2] = max(maxDy[1], maxDy[2]) + input[2];
        maxDy[1] = max(max(tmp0, maxDy[1]), tmp2) + input[1];

        // 최소값 구하기
        tmp0 = minDy[0];
        tmp2 = minDy[2];
        minDy[0] = min(minDy[0], minDy[1]) + input[0];
        minDy[2] = min(minDy[1], minDy[2]) + input[2];
        minDy[1] = min(min(tmp0, minDy[1]), tmp2) + input[1];
    }

    cout << max(max(maxDy[0], maxDy[1]), maxDy[2]) << " ";
    cout << min(min(minDy[0], minDy[1]), minDy[2]);
    return 0;
}
