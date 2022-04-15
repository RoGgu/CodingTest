#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>   // cin,cout말고 이제 c에서 제공하는 sanf, printf 사용 - 속도가 조금 더 빠름
#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
#include<cstdlib>

using namespace std;

// 내가 푼 방식
// 1이 토마토가 익은 거니까 익은 토마토 vector에 넣는다.
// vector에 있는 익은 토마토 queue에 다 넣고 vector 리셋 후 q 돌면서 다 꺼내서 주위 안익은 토마토 익게하고 그 익은 토마토 vector에 넣는다.
// 이 과정을 반복 하는데 vector에 있는거 queue에 다 넣을때 날짜 하루 지난거고 중간에 익은 토마토 개수가 처음 세팅한 토마토의 총 개 수랑 같으면
// 전부 다 익은거고 수가 다른데 저번에 익은 토마토 수랑 다음 토마토 익은 수랑 같으면 익지 않은 남은 토마토는 있지만 더 이상 익게할 수 없으니 -1 출력

// - 강사 푸는방식도 나주엥 코드로 짜보자
// 강사가 푸는 방식은 2차원 배열을 더 만들어 토마토 마다 익은 날짜를 세팅해서 BFS 다 돈 후
// 날마다 익은날 체크하는 2중 배열 도는데 익지 않은 토마토가 있다면 -1 표시,
// 다 익었으면 익은 날 제일 큰게 총 걸린 날이니까 그날을 출력

struct Loc // 토마토 좌표포시 Q에 넣는 용도
{
    int _y;
    int _x;

    Loc(int y, int x)
    {
        _y = y;
        _x = x;
    }
};

int main()
{
    ios_base::sync_with_stdio(false);
    //freopen("input.txt", "rt", stdin); // input.txt 파일 읽기
    int n, m, tmp, cnt = 0, chCnt = 0, lastChCnt = 0, res = 0;;
    int dy[4] = { -1, 1,  0, 0, }; // 4방향 회전 상하좌우
    int dx[4] = { 0, 0, -1, 1, };

    cin >> m >> n;
    vector<vector<int>> map(n, vector<int>(m)); // 토마토 맵
    queue<Loc> q; // 현재 익은 토마토들
    vector<Loc> v; // 익은 토마토 queue에 넣기전 임시 저장

    for (int y = 0; y < n; y++)
    {
        for (int x = 0; x < m; x++)
        {
            cin >> tmp;
            map[y][x] = tmp;
            if (tmp == 0 || tmp == 1)
            {
                cnt++;
                if (tmp == 1) // 익은 토마토는 v에 넣는다
                {
                    chCnt++;
                    v.push_back(Loc(y, x));
                }
            }
        }
    }

    while (true)
    {
        for (int i = 0; i < v.size(); i++) // v 돌면서 현재 익어 있는 토마토 q에 넣고 리셋
        {
            q.push(v[i]);
        }
        v.clear();

        if (lastChCnt == chCnt) // 만약 저번에 익은 토마토 총 수랑 이번에 익은 토마토 총 수랑 같으면 더 이상 익을토마토가 없다는 뜻 그럼 익지 않는 토마토 있으니 -1 리턴
        {
            res = -1;
            break;
        }
        else if (cnt == chCnt) // 토마토 다 익었다
            break;
        else
            res++; // 날짜 증가


        lastChCnt = chCnt;

        while (q.empty() == false) // 익은 토마토 하나씩 뺴면서 주위에 안익은 토마토 익힌다
        {
            Loc pos = q.front();
            q.pop();

            for (int i = 0; i < 4; i++)
            {
                int nextY = pos._y + dy[i];
                int nextX = pos._x + dx[i];

                if (nextY < 0 || nextY >= n || nextX < 0 || nextX >= m)
                    continue;

                if (map[nextY][nextX] == 0)
                {
                    chCnt++;
                    v.push_back(Loc(nextY, nextX));
                    map[nextY][nextX] = 1;
                }
            }
        }

    }

    cout << res << endl; // 총 소요 날짜
    return 0;
}
