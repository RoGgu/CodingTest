#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<string>
#include<vector>
#include<queue>
#include<algorithm>
#include<cmath>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    freopen("input.txt", "rt", stdin);
    int N, K, count = 1;
    cin >> N >> K;
    queue<int> q;
    vector<int> v;
    for (int i = 1; i <= N; i++)
    {
        q.push(i);
    }

    while (!q.empty())
    {
        int tmp = q.front();
        q.pop();

        if (count == K)
        {
            v.push_back(tmp);
            count = 1;
        }
        else
        {
            q.push(tmp);
            count++;
        }
    }

    cout << "<" << v[0];
    for (int i = 1; i < v.size(); i++)
    {
        cout << ", " << v[i];
    }
    cout << ">";

    return 0;
}
