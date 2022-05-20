#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>
#include<stack>

using namespace std;

// DFS계산을 통해서 구했는데 시간초과나서 방법을 도저히 못 찾아서
// 풀이보고 코드 작성 (다음에 다시 풀기)

// 현재 i번째 집까지의 dy 값은 현재 집 색칠 색깔과 다른집에 해당 dy값들 중 작은 값 더하기
// 현재 집 칠하는 비용
// 그렇게 해서 i번쨰 집 컬러별로 dy 값들중 제일 작은게 답이다.

int main() {
    ios::sync_with_stdio(false);
    freopen("input.txt", "rt", stdin);

    int n;
    cin >> n;
    int cost[3];
    vector<vector<int>> dy(n + 1, vector<int>(3));
    // dy 계산을 위한 가상의 0번째 집 0으로 초기화
    dy[0][0] = 0;
    dy[0][1] = 0;
    dy[0][2] = 0;

    for (int i = 1; i <= n; i++)
    {
        cin >> cost[0] >> cost[1] >> cost[2]; // 각 집 칠하는 RGB 비용들
        // dy[i][color]은 i번째 집 칠하는 비용 + 그 전집들 전체 칠하는 전체 비용 중 작은거랑 더한다 (이떄 전집들 검사할때 현재 칠하는 색과 다른색들만 탐색)
        dy[i][0] = cost[0] + min(dy[i - 1][1], dy[i - 1][2]);
        dy[i][1] = cost[1] + min(dy[i - 1][0], dy[i - 1][2]);
        dy[i][2] = cost[2] + min(dy[i - 1][0], dy[i - 1][1]);
    }

    cout << min(dy[n][0], min(dy[n][1], dy[n][2])); // 마지막 최종 집 색깔별로해서 그 집까지의 전체 비용중 제일 작은거 고름
    return 0;
}