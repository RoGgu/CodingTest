#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<vector>
#include<queue>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    freopen("input.txt", "rt", stdin);
    int N, K, X, res = 0;
    cin >> N >> K;
    X = N;
    queue<int> q;
    vector<int> cnts(100001, 0); // 거리별 걸린 시간 세팅

    if (N == K) // 이미 서로 같은 위치면은 시간은 0초 걸린다.
    {
        std::cout << "0" << endl;
        return 0;
    }

    q.push(X);
    while (q.empty() == false)
    {
        int cur = q.front();
        int curCnt = cnts[cur];
        q.pop();

        // +1, -1, *2 세가지 경우를 BFS탐색으로 구한다.

        if (cur + 1 == K)
        {
            res = curCnt + 1;
            break;
        }
        else if (cur + 1 < cnts.size() && cnts[cur + 1] == 0)
        {
            cnts[cur + 1] = curCnt + 1;
            q.push(cur + 1);
        }

        if (cur - 1 == K)
        {
            res = curCnt + 1;
            break;
        }
        else if (cur - 1 < cnts.size() && cnts[cur - 1] == 0)
        {
            cnts[cur - 1] = curCnt + 1;
            q.push(cur - 1);
        }

        if (cur * 2 == K)
        {
            res = curCnt + 1;
            break;
        }
        else if (cur * 2 < cnts.size() && cnts[cur * 2] == 0)
        {
            cnts[cur * 2] = curCnt + 1;
            q.push(cur * 2);
        }
    }

    std::cout << res << endl;
    return 0;
}