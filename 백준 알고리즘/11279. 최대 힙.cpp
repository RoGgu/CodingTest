#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include <string.h>
#include<vector>
#include<queue>
using namespace std;

int main() {
    freopen("input.txt", "rt", stdin);
    int n, x;
    priority_queue<int> pq;
    scanf("%d", &n); // 속도 떄문에 scanf, printf 씀

    for (int i = 0; i < n; i++)
    {
        scanf("%d", &x);
        if (x == 0)
        {
            if (pq.empty())
                printf("0\n");
            else
            {
                printf("%d\n", pq.top());
                pq.pop();
            }
        }
        else
            pq.push(x);
    }

    return 0;
}