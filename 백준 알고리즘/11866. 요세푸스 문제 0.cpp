#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<queue>
#include<vector>
#include<algorithm>
#include<math.h>
#include<map>
#include<set>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    freopen("input.txt", "rt", stdin); // input.txt 파일 읽기
    int N, K;
    cin >> N >> K;
    queue<int> q;
    vector<int> v;
    for (int i = 1; i <= N; i++)
    {
        q.push(i);
    }

    int cnt = 0;
    while (q.size() != 1)
    {
        int tmp = q.front();
        q.pop();
        ++cnt;
        if (cnt == K)
        {
            cnt = 0;
            v.push_back(tmp);
        }
        else
        {
            q.push(tmp);
        }
    }

    v.push_back(q.front());
    cout << "<" << v[0];
    for (int i = 1; i < v.size(); i++)
    {
        cout << ", " << v[i];
    }
    cout << ">";

    return 0;
}