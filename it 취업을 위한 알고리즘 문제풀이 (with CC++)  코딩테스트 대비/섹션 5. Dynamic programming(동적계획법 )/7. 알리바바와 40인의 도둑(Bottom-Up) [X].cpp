#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<stdio.h>	// cin,cout말고 이제 c에서 제공하는 sanf, printf 사용 - 속도가 조금 더 빠름
#include<vector>
#include<algorithm>

using namespace std;

// 7. 알리바바와 40인의 도둑(Bottom-Up)

// 다이나믹 방식으로 하는데 다이나믹 세팅 방법이
// 처음에는 가장자리로 맨위와, 맨 왼쪽은 경로가 하나씩밖에 없으니
// 먼저 y쪽 0번인덱스 x쪽 0번인덱스의 다이나믹값을 쭉 세팅해준다.
// 그후 [1][1] 인덱스 부터 자기 자신의 위와 왼쪽에 다이나믹값 비교해서
// 작은애 선택후 현재 map에 값을 더한걸 다이나믹 값으로 세팅
// 그럼 마지막 dy[n-1][n-1]에 최소 비용의 결과값이 있다.


int main() {
    //freopen("input.txt", "rt", stdin);
    cin.tie(NULL);
    ios::sync_with_stdio(false);
    int n, tmp;
    cin >> n;
    vector<vector<int>> map(n, vector<int>(n));
    vector<vector<int>> dy(n, vector<int>(n));


    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> tmp;
            map[i][j] = tmp;
        }
    }
    dy[0][0] = map[0][0];

    for (int i = 1; i < n; i++) // 가장자리 다이나믹 값 다 세팅
    {
        dy[0][i] = dy[0][i - 1] + map[0][i];
        dy[i][0] = dy[i - 1][0] + map[i][0];
    }

    for (int y = 1; y < n; y++)
    {
        for (int x = 1; x < n; x++)
        {
            // 위와 왼쪽에 다이나믹값 비교해서 작은 값 선택해서 현재 map값 더해서 다이나믹값 세팅
            // dy[y][x] = min(dy[y - 1][x], dy[y][x - 1]); // min코드써서 한줄로도 가능
            if (dy[y - 1][x] < dy[y][x - 1])
                dy[y][x] = map[y][x] + dy[y - 1][x];
            else
                dy[y][x] = map[y][x] + dy[y][x - 1];
        }
    }

    cout << dy[n - 1][n - 1] << endl; // 도착지점에 현재까지 걸린 비용이있다.
    return 0;
}