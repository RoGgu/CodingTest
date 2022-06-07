#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<string.h>
#include<vector>
#include<queue>
#include<algorithm>
using namespace std;

int ch[10001];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    freopen("input.txt", "rt", stdin);
    int n;
    scanf("%d", &n);

    for (int i = 0; i < n; i++)
    {
        int tmp;
        scanf("%d", &tmp);
        ch[tmp] += 1;
    }

    for (int i = 1; i <= 10000; i++) // 입력 수가 너무 많아서 카운터하는 방식으로 수 출력
    {
        for (int j = 0; j < ch[i]; j++)
            printf("%d\n", i);
    }

    return 0;
}