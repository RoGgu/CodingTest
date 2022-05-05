#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>   // cin,cout말고 이제 c에서 제공하는 sanf, printf 사용 - 속도가 조금 더 빠름
#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
#include<cstdlib>

using namespace std;

// 12. 플로이드-와샬(그래프 최단거리)

// 특정 노드가 다른 전체 노드로 가는 최소비용이다.

// 일단 직통연결된 값을 dis에 세팅하고 모든 노드를 k번으로 매겨서
// k번 노드를 거쳤을때에 비용이랑 기존에 dis값이랑 비교해서 k번 노드 거쳐서 가는게 더 비용이 적으면 바꿔준다.
// 이때 k를 1번노드부터 시작해서 dis값은 냅색 알고리즘처럼 1번 거쳤을 때 dis값, 그 다음 2번...3번...이렇게 거쳐가는 노드값을 계산해서 최소 값으로 세팅한다.
// ex)예를들어 기존에 이미 1,2번노드 거친다 가정했을 떄 값이 3번노드 추가로 거쳤을떄 값보다 작으면 그대로 둔다.

// [중요] k번이 1번부터 시작한다 해서 그 순서대로 이동하는건 아니다 dis[i][k] + dis[k][j] 이렇게 계산함으로
// 해당 노드에 최솟값으로 계산해서 어떻게 거쳐왔는지는 순서가 다를 수 있다.
// ex) dis[1][3] + dis[3][4] 면 1-3-4 이런 순서로 가는게 아니라 1번부터 3번까지 갔을떄 최솟값 + 3번부터 4번 갓을때 최솟값이라 순서는 따로 구해야 한다.

// 그렇게 dis[i][j] 기존 값으랑 k번 노드 거쳐서 간 값 dis[i][k] + dis[k][j] 랑 비교해서 작은값 세팅한다.

// 이때 만약 i랑 k값이 같으면 이중으로 비용 계산되는거 같지만 애초에 자기자신에 이동비용은 0이라서 상관없다.


int main()
{
    freopen("input.txt", "rt", stdin); // input.txt 파일 읽기
    int n, m, s, e, c;
    cin >> n >> m;
    vector<vector<int>> dis(n + 1, vector<int>(n + 1, 5000)); // 못 가는애는 5000으로 세팅

    for (int i = 1; i <= n; i++) // 자기자신으로 이동 비용은 0으로 세팅
    {
        dis[i][i] = 0;
    }

    for (int i = 0; i < m; i++)// 처음 가는데 이동비용들 세팅, 못가는 애는 기본 5000값으로 설정되어있다.
    {
        cin >> s >> e >> c;
        dis[s][e] = c;
    }

    for (int k = 1; k <= n; k++) // k번 노드를 거쳐간다는 개념, 1부터 해서 5번노드까지 거쳐갓을때에 최소 비용 값이 갱신된다, 하지만 가는 순서는 다를 수 있다.
    {
        for (int i = 1; i <= n; i++)
        {
            // 거쳐가는게 시작 지점이면 넘어가도 되지만 사실 자기자신 에서 자기를 거쳐가는 비용은 0이라 그냥 더해도 상관 없다.
            if (i == k)
                continue;

            for (int j = 1; j <= n; j++)
            {
                // 현재 최소 값으로 세팅된 dis값보다 k번을 거쳐서 가는게 더 적은 비용일 경우 바꿔준다.
                if (dis[i][j] > dis[i][k] + dis[k][j])
                    dis[i][j] = dis[i][k] + dis[k][j];

                // 한줄 코딩으로 가능
                //dis[i][j] = min(dis[i][j], dis[i][k] + dis[k][j]);
            }
        }
    }

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            if (dis[i][j] == 5000) // 5000값 그대로면 못 가는 곳이라서 M으로 표시
                cout << "M" << " ";
            else
                cout << dis[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}

