#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<stdio.h>	// cin,cout말고 이제 c에서 제공하는 sanf, printf 사용 - 속도가 조금 더 빠름
#include<vector>
#include<algorithm>
#include<queue>

using namespace std;

// 14. 위상정렬(그래프)

// 일단 작업 표시를 나타내는 map을 만들고
// 해당 작업을 하기전에 선행작업을 얼만큼 해야하는지 나타내는 work 배열로 선핵작업 목록 세팅한다.
// 선행 작업 없는애들은 q에 넣어서 작업 돌리고 해당 작업이 선행작업으로 되어있는애들 찾아서 work배열에 하나 줄여준다.
// 그렇게 q에 더이상 담을 일이 없을떄까지 다 돈다


int main() {
    ios::sync_with_stdio(false);
    //freopen("input.txt", "rt", stdin);
    int n, m, s, e;
    cin >> n >> m;
    vector<vector<int>> map(n + 1, vector<int>(n + 1, 0));
    vector<int> work(n + 1, 0); // 진입 차수 카운터 배열
    queue<int> q; // 진입 차수가 없는 현재 일을 해야하는애들을 담아둔 q

    for (int i = 0; i < m; i++)
    {
        cin >> s >> e;
        map[s][e] = 1;
        work[e]++;
    }

    for (int i = 1; i <= n; i++) // 선행작업(진입차수) 없는애들 일 하도록 q에 넣어준다
    {
        if (work[i] == 0)
            q.push(i);
    }

    while (q.empty() == false)
    {
        int now = q.front(); // 현재 일 하는애
        q.pop();
        cout << now << " "; // 일 하는애 출력


        for (int i = 1; i <= n; i++)
        {
            if (map[now][i] == 1)
            {
                work[i]--; // 현재 작업하면 그 다음일 선행작업이 하나 줄어드니까 하나 감소시켜줌

                if (work[i] == 0) // 선행작업 없으면 이제 일할 목록에 넣어준다
                    q.push(i);
            }
        }
    }

    return 0;
}