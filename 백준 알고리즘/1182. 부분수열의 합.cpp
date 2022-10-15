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


int n, s;
int cnt = 0;
int arr[21];

void DFS(int idx, int sum, int size)
{
    if (idx == n)
    {
        // 인덱스 전부 체크 했을때 값이 s와 같고 한 개라도 더한 수가 있을경우 카운트
        if (sum == s && size != 0)
        {
            cnt++;
        }
        return;
    }
    DFS(idx + 1, sum + arr[idx], size + 1); // 현재 Index수 더하는 경우
    DFS(idx + 1, sum, size); // 더하지 않는 경우
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    freopen("input.txt", "rt", stdin);
    cin >> n >> s;
    for (int i = 0; i < n; i++)
        cin >> arr[i];

    DFS(0, 0, 0);
    cout << cnt;

    return 0;
}
