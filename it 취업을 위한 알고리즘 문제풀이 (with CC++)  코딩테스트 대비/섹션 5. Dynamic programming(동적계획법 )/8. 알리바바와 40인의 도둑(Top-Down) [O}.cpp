#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<stdio.h>	// cin,cout말고 이제 c에서 제공하는 sanf, printf 사용 - 속도가 조금 더 빠름
#include<vector>
#include<algorithm>

using namespace std;

// 8. 알리바바와 40인의 도둑(Top-Down)

// DFS로 이용해서 푸는데 메모제이션 사용해서 풀이

int arr[21][21];
int dy[21][21];

int DFS(int y, int x)
{
    if (dy[y][x] != 0) // 이미 다이나믹 값있으면 그 값 사용
        return dy[y][x];

    if (x == 0 && y == 0)
    {
        return arr[0][0];
    }
    else
    {
        if (y == 0) // y끝이면 왼쪽으로만 이동
            return dy[y][x] = DFS(y, x - 1) + arr[y][x];
        else if (x == 0) // x 끝이면 위로만 이동
            return dy[y][x] = DFS(y - 1, x) + arr[y][x];
        else // 둘다 끝이 아니면 더 작은 값을 세팅
            return dy[y][x] = min(DFS(y - 1, x), DFS(y, x - 1)) + arr[y][x];
    }
}

int main() {
    ios::sync_with_stdio(false);
    //freopen("input.txt", "rt", stdin);
    int n;
    cin >> n;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> arr[i][j];
        }
    }

    cout << DFS(n - 1, n - 1) << endl;  // 원점에서 최종 목적지 n-1,n-1까지 오는데 걸리는 최소 비용

    return 0;
}