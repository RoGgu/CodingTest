#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<vector>
#include<queue>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    freopen("input.txt", "rt", stdin);
    int n, m, a, b, cnt = 0;
    cin >> n >> m;
    vector<vector<int>> map(n + 1, vector<int>(n + 1, 0)); // 연결된 맵 체크용
    vector<int> bi(n + 1, 0); // 바이러스애들 체크용도
    queue<int> q;

    for (int i = 0; i < m; i++)
    {
        cin >> a >> b;
        map[a][b] = 1;
        map[b][a] = 1;
    }

    q.push(1);
    bi[1] = 1;

    while (q.empty() == false)
    {
        int temp = q.front();
        q.pop();

        for (int i = 1; i <= n; i++)
        {
            if (map[temp][i] == 1 && bi[i] == 0)
            {
                cnt++;
                bi[i] = 1; // 바이러스 걸렸다고 표시
                map[temp][i] = 0; // 중복 탐색 막기위해 0으로 바꿔준다
                map[i][temp] = 0;
                q.push(i); // 다음 탐색을 위해 push
            }
        }
    }

    cout << cnt << endl;
    return 0;
}