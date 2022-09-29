#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<queue>
#include<vector>
#include<algorithm>
#include<math.h>
#include<map>
#include<set>

using namespace std;

void Hanoi(int n, int form, int by, int to)
{
    if (n == 0) // 이동할 원판 없으면 return
        return;
    else
    {
        Hanoi(n - 1, form, to, by); // n을 to(목적지)로 이동시키기 위해선 n개 위에 n-1개의 원판을 전부 경유지에 옮겨야한다.
        cout << form << " " << to << "\n"; // 원판 n을 to 목적지로 이동
        Hanoi(n - 1, by, form, to); // n을 옮기기 위해서 n-1개 경유지로 옮겼던거 이제 to 목적지로 이동시킨다.
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    freopen("input.txt", "rt", stdin); // input.txt 파일 읽기
    int n, k;
    cin >> n;
    k = pow(2, n) - 1; // 하노이 최소이동 횟수는 (2^n) -1
    cout << k << "\n"; // 최소이동 횟수 출력
    Hanoi(n, 1, 2, 3); //  1에 있는 것들을 2를 거쳐 3으로 전부 이동시켜야 한다.
    return 0;
}