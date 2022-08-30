#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<string>
#include<vector>
#include<queue>
#include<algorithm>
#include<cmath>
#include<map>
using namespace std;


struct st
{
    st(int t, int p)
    {
        time = t;
        pos = p;
    }

    int time;
    int pos;

};

struct compare {
    bool operator()(const st& st1, const st& st2)
    {
        return st1.time > st2.time;
    }
};

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    freopen("input.txt", "rt", stdin);
    int x, k;
    cin >> x >> k;
    vector<int>dy(200001, 2147000000); // 각 인덱스를 거리로 생각하고 도달하는데 걸린 소요시간을 최소 시간으로 세팅한다.
    dy[x] = 0; // 시작 위치는 소요시간 0
    priority_queue<st, vector<st>, compare> pq;

    pq.push(st(0, x));


    while (!pq.empty())
    {
        int cTime = pq.top().time;
        int cPos = pq.top().pos;
        st now = pq.top();
        pq.pop();

        if (cPos == k) // 우선순위 큐로 하나씩 체크해서 처음 발견한 순간이 제일 적은 시간을 소요한 경우이다.
        {
            dy[k] = cTime;
            break;
        }

        // 현재 거리와 도달 위치에 차이에 따라서 pq에 세팅하는 거리와 시간 경우를 다르게 한다.

        if (cPos > k)
        {
            if (dy[cPos - 1] > cTime + 1)
            {
                dy[cPos - 1] = cTime + 1;
                pq.push(st(cTime + 1, cPos - 1));
            }
        }
        else if (cPos < k)
        {
            if (dy[cPos * 2] > cTime)
            {
                dy[cPos * 2] = cTime;
                pq.push(st(cTime, cPos * 2));
            }

            if (dy[cPos + 1] > cTime + 1)
            {
                dy[cPos + 1] = cTime + 1;
                pq.push(st(cTime + 1, cPos + 1));
            }

            if (cPos - 1 >= 0)
            {
                if (dy[cPos - 1] > cTime + 1)
                {
                    dy[cPos - 1] = cTime + 1;
                    pq.push(st(cTime + 1, cPos - 1));
                }
            }
        }
    }

    cout << dy[k];
    return 0;
}
