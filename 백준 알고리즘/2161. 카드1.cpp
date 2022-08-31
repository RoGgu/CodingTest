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
    queue<int> q;
    cin >> N;
    for (int i = 1; i <= N; i++) {
        q.push(i);
    }

    while (q.size() != 1)
    {
        cout << q.front() << " ";
        q.pop();
        q.push(q.front());
        q.pop();
    }

    cout << q.front();
    return 0;
}
