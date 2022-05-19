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
    int n, A, B; // A가 B가 되어야 한다.
    cin >> n;

    for (int i = 0; i < n; i++)
    {
        int ch[10000] = { 0 }; // 똑같은 수 재방문 안하기 위해서 체크
        queue<pair<int, string>> q;
        cin >> A >> B;
        q.push(make_pair(A, "")); // BFS탐색을 위해 담아둔다.

        while (q.empty() == false) // 사실 q가 빌 수는 없다 중간에 숫자가 B가 되면 멈추도록 작성
        {
            int tmpN = q.front().first;
            string tmpS = q.front().second; // 현재 수 까지왓을때 문자열
            q.pop();

            if (tmpN == B) // B가 되면 현재까지 온 문자열 출력하고 멈춘다.
            {
                cout << tmpS << endl;
                break;
            }
            else
            {
                // 각각의 조건에 맞는수 중복체크하고 넣는다.
                int dN = tmpN * 2 % 10000;
                if (ch[dN] == 0)
                {
                    q.push(make_pair(dN, tmpS + "D"));
                    ch[dN] = 1;
                }

                int sN = 0;
                if (tmpN == 0)
                    sN = 9999;
                else
                    sN = tmpN - 1, tmpS;
                if (ch[sN] == 0)
                {
                    q.push(make_pair(sN, tmpS + "S"));
                    ch[sN] = 1;
                }

                int lN = 0;
                lN = (tmpN * 10 % 10000) + tmpN / 1000;
                if (ch[lN] == 0)
                {
                    q.push(make_pair(lN, tmpS + "L"));
                    ch[lN] = 1;
                }

                int rN = 0;
                if (tmpN % 10 != 0)
                    rN = tmpN / 10 + (tmpN % 10 * 1000);
                else
                    rN = tmpN / 10;
                if (ch[rN] == 0)
                {
                    q.push(make_pair(rN, tmpS + "R"));
                    ch[rN] = 1;
                }
            }
        }
    }

    return 0;
}
