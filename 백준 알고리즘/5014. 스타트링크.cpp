#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>
#include<stack>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    freopen("input.txt", "rt", stdin);
    int F, S, G, U, D;
    cin >> F >> S >> G >> U >> D;
    queue<pair<int, int>> q;
    vector<int> ch(F + 1, 0); // 중복 체크 배열

    q.push(make_pair(S, 0));

    while (q.empty() == false)
    {
        int cur = q.front().first;
        int cnt = q.front().second;
        q.pop();

        if (cur == G) // 층 도달하면 종료
        {
            cout << cnt << endl;
            exit(0);
        }
        else
        {
            int nu = cur + U; // 올라갈 층
            int nd = cur - D; // 내려갈 층

            if (cur != nu && nu <= F && ch[nu] == 0) // // U가 0일경우 제자리니까 패스, F층까지 밖에 없음, 중복 체크
            {
                ch[nu] = 1;
                q.push(make_pair(nu, cnt + 1));
            }

            if (cur != nd && nd >= 1 && ch[nd] == 0) // D가 0일경우 제자리니까 패스, 1층부터 시작, 중복 체크
            {
                ch[nd] = 1;
                q.push(make_pair(nd, cnt + 1));
            }
        }
    }

    cout << "use the stairs" << endl;
    return 0;
}
