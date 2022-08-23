#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<string>
#include<vector>
#include<queue>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    freopen("input.txt", "rt", stdin);
    int n, tmp, maxW = 0;
    cin >> n;
    priority_queue<int, vector<int>, greater<int>> pq; // 오름차순 우선순위 큐
    for (int i = 0; i < n; i++)
    {
        cin >> tmp;
        pq.push(tmp);
    }

    while (!pq.empty())
    {
        tmp = pq.top();

        if (tmp * pq.size() >= maxW) // 현재 꺼낸 수가 가장 크게 들 수 있는 무게 * 이보다 무게 더 들 수 있는 로프에 수가 현재 최고로 들 수 있는 무게보다 크면 세팅
        {
            maxW = tmp * pq.size(); 
        }

        pq.pop();
    }

    cout << maxW;
    return 0;
}
