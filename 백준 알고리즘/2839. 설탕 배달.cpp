#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include <string.h>
#include<vector>
#include<queue>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    freopen("input.txt", "rt", stdin);
    int n, cnt = 0;
    cin >> n;
    priority_queue<int, vector<int>, greater<int>> pq; // 가장 작은거부터 하는 우선순위 큐 사용

    pq.push(n);
    vector<int> ch(5001, 2147000000);
    ch[n] = 0;

    while (!pq.empty())
    {
        int tmp = pq.top();
        pq.pop();

        if (tmp - 5 == 0) // 5kg 포대 이용할경우
        {
            if (ch[0] > ch[tmp] + 1)
                ch[0] = ch[tmp] + 1;
        }
        else if (tmp > 5 && ch[tmp - 5] > ch[tmp] + 1)
        {
            ch[tmp - 5] = ch[tmp] + 1;
            pq.push(tmp - 5);
        }

        if (tmp - 3 == 0)  // 3kg 포대 이용할경우
        {
            if (ch[0] > ch[tmp] + 1)
                ch[0] = ch[tmp] + 1;
        }
        else if (tmp > 3 && ch[tmp - 3] > ch[tmp] + 1)
        {
            ch[tmp - 3] = ch[tmp] + 1;
            pq.push(tmp - 3);
        }
    }

    if (ch[0] == 2147000000) // ch[0] 설정된게 없다면 5,3 포대 두 종류로 운반할 수 없는 경우
        cout << -1 << endl;
    else
        cout << ch[0] << endl;

    return 0;
}