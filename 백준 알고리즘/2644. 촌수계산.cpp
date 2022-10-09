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
    int n, m, x, y, n1, n2;
    cin >> n;
    cin >> n1 >> n2;
    cin >> m;
    vector<vector<int>> graph(n + 1, vector<int>(n + 1, 0)); // 부모자식 연결 관계 양방향으로 설정
    vector<int> ch(n + 1, 0); // 사촌 확인헀는지 체크 배열

    for (int i = 0; i < m; i++)
    {
        cin >> x >> y;
        graph[x][y] = 1;
        graph[y][x] = 1;
    }

    ch[n1] = 1; // n1부터 시작해서 n2 찾을떄가지 한다.
    int res = 2147000000;
    queue<pair<int, int>>q;
    q.push(make_pair(n1, 0)); // 현재 사람번호 , 그 사람번호 까지 촌 수

    while (!q.empty())
    {
        int now = q.front().first;
        int nCnt = q.front().second;
        q.pop();

        for (int i = 0; i <= n; i++)
        {
            if (graph[now][i] == 1 && ch[i] == 0)
            {
                if (i == n2) // 사촌 찾으면 종료
                {
                    res = min(res, nCnt + 1);
                    break;
                }
                else
                {
                    ch[i] = 1;
                    q.push(make_pair(i, nCnt + 1));
                }
            }
        }
    }

    if (res == 2147000000) // 만약 사촌 연결 안되어 있으면 -1 출력
        res = -1;

    cout << res;
    return 0;
}
