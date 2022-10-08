#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<string>
#include<vector>
#include<stack>
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
    int N, tmp;
    cin >> N;
    priority_queue<int, vector<int>, greater<int>> pq; //오름차순으로 낮은거부터 top에서 출력하도록 우선순위 큐 선언

    for (int i = 0; i < N; i++)
    {
        cin >> tmp;

        if (tmp == 0) // 0 이면 출력하는ㄷ qp 비어있으면 0 출력 아니면 제일 낮은거 top에 있는 수 출력하고 삭제
        {
            if (pq.empty())
                cout << "0" << "\n";
            else
            {
                cout << pq.top() << "\n";
                pq.pop();
            }
        }
        else
        {
            pq.push(tmp);
        }
    }


    return 0;
}
