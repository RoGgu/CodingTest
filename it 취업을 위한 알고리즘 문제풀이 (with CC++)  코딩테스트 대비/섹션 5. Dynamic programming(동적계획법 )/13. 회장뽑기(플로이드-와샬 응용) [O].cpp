#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>   // cin,cout말고 이제 c에서 제공하는 sanf, printf 사용 - 속도가 조금 더 빠름
#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
#include<cstdlib>

using namespace std;

// 13. 회장뽑기(플로이드-와샬 응용)

// 12번 프롤이드-와샬 문제 코드랑 dis 그래프 세티하는건 똑같다
// - 특정 노드에서 다른 노드까지 가는데 필요한 비용

// 이제 dis맵을 가지고 다른 노드까지 가는데 필요한 비용의 최대값으 각자 세팅하고
// 거기서 값이 제일 작은애를 가지는 애들을 찾아서 출력한다.

int main()
{
    //freopen("input.txt", "rt", stdin); // input.txt 파일 읽기
    int n, a, b;
    cin >> n;
    vector<vector<int>> dis(n + 1, vector<int>(n + 1, 5000));
    vector<int> value(n + 1, 0); // 각 회원에 점수
    vector<int> result; // 값이 가장 작은애들(회장이 되는 애들) 담아두는 배열
    int score = 2147000000; // 회장이 되는 점수

    for (int i = 1; i <= 5; i++) // 자기자신 비용은 0으로 세팅
        dis[i][i] = 0;

    while (true)
    {
        cin >> a >> b;
        if (a == -1 || b == -1) // -1나오면 입력 종료
            break;

        // 양방향이라서 서로 1 세팅
        dis[a][b] = 1;
        dis[b][a] = 1;
    }

    // 3중포문 돌면서 프로이드-워샬로 비용맵 세팅
    for (int k = 1; k <= n; k++)
    {
        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= n; j++)
            {
                dis[i][j] = min(dis[i][j], dis[i][k] + dis[k][j]);
            }
        }
    }

    for (int i = 1; i <= n; i++)
    {
        int maxNum = -1;
        for (int j = 1; j <= n; j++)
        {
            if (dis[i][j] > maxNum)
                maxNum = dis[i][j];
        }
        value[i] = maxNum; // i번의 점수 세팅 (다른 노드가는데 필요한 최대 값)

        // 현재 회장이 되는 값보다 자기 값이 더 낮으면
        // 기존 리스트애들 정리하고 자기부터 회장되는값으로 세팅해서 넣는다
        if (value[i] < score)
        {
            score = value[i];
            result.clear();
            result.push_back(i);
        }
        else if (value[i] == score) // 똑같을 경우 회장 될 수 있으니까 배열에 추가
        {
            result.push_back(i);
        }
    }

    cout << score << " " << result.size() << endl;

    for (int i = 0; i < result.size(); i++)
        cout << result[i] << " ";
    return 0;
}

