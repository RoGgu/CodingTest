#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    freopen("input.txt", "rt", stdin);
    int m, n;
    int res = 0, tomato = 0, cnt = 0, lastCnt = 0;
    cin >> m >> n;
    vector<vector<int>> map(n, vector<int>(m));
    queue<pair<int, int>> q;
    int dy[] = { -1, 1,  0, 0 };
    int dx[] = { 0, 0, -1, 1 };
    int qNum = 0;
    int qNextNum = 0;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> map[i][j];
            if (map[i][j] == 0 || map[i][j] == 1)
            {
                tomato++;
                if (map[i][j] == 1)
                {
                    cnt++;
                    qNum++;
                    q.push(make_pair(i, j));
                }
            }
        }
    }

    if (cnt == tomato) // 처음부터 토마토 다 익어있으면 0 출력
    {
        cout << 0 << endl;
    }
    else
    {
        while (true)
        {
            // q에 qNum 이미 익은 토마토들 그 이후는 다음에 익을 토마토들 넣어둔다.
            while (q.empty() == false && qNum > 0) // 이미 익은 토마토만 꺼내서 주위 토마토 익게 만들고 담는다.
            {
                pair<int, int> p = q.front();
                q.pop();
                qNum--;  // 익은 토마토 하나 카운트

                for (int i = 0; i < 4; i++) // 상하좌우 돌면서 안 익은 토마토 있으면 익힌다음에 넣어둠
                {
                    int nY = p.first + dy[i];
                    int nX = p.second + dx[i];

                    if (nY < 0 || nY >= n || nX < 0 || nX >= m) // 인덱스 범위 체크
                        continue;

                    if (map[nY][nX] == 0) // 안익은 토마토 있으면 익힌 다음에 익은토마토 갯 수 증가시키고 다음에 체크할 익을토마토로 하기위해 q에 넣어줌
                    {
                        cnt++;
                        map[nY][nX] = 1;
                        q.push(make_pair(nY, nX));
                        qNextNum++;
                    }
                }
            }

            qNum = qNextNum; // 다음 체크할 토마토 갯수 옮기고
            qNextNum = 0; // 초기화

            res++; // 날짜지남

            if (cnt == tomato) // 전체 토마토 수랑 현재 익은토마토 수랑 같으면 다 익은거
            {
                cout << res << endl;
                break;
            }
            else if (lastCnt == cnt) // 만약 저번 날이랑 익은 토마토 갯 수가 똑같으면 더 이상 익힐 수 없는 상태라 -1 출력하고 종료
            {
                cout << -1 << endl;
                break;
            }

            lastCnt = cnt; // 날짜별 익은토마토 체크용
        }
    }

    return 0;
}