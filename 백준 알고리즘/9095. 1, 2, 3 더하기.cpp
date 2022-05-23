#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<vector>
#include<queue>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    freopen("input.txt", "rt", stdin);
    int n, num;
    int cnt = 0;
    cin >> n;

    for (int i = 0; i < n; i++)
    {
        cin >> num;
        cnt = 0;
        queue<int>q;
        q.push(num);

        while (q.empty() == false)
        {
            int tmp = q.front();
            q.pop();

            if (tmp == 0) // 0이면 제대로 수 구해진거라서 개수 증가
                cnt++;
            else // 특정 수 씩 빼가지고 BFS 탐색
            {
                if (tmp - 1 >= 0)
                    q.push(tmp - 1);

                if (tmp - 2 >= 0)
                    q.push(tmp - 2);

                if (tmp - 3 >= 0)
                    q.push(tmp - 3);
            }
        }
        cout << cnt << endl;
    }
    return 0;
}