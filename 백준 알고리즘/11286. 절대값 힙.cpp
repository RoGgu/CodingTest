#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<string>
#include<vector>
#include<queue>
#include<algorithm>
#include <map>
using namespace std;

struct cmp {
    bool operator()(int a, int b)
    {
        if (abs(a) == abs(b))
            return a > b;
        return abs(a) > abs(b);
    }
};

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    freopen("input.txt", "rt", stdin);

    priority_queue<int, vector<int>, cmp> pq;
    int N;
    cin >> N;
    int in = 0;
    while (N--)
    {
        cin >> in;
        if (in == 0)
        {
            if (pq.empty())
            {
                cout << 0 << "\n"; continue;
            }

            cout << pq.top() << "\n"; pq.pop();
        }
        else
        {
            pq.push(in);
        }
    }
}
