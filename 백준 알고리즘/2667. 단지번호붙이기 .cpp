#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>

using namespace std;

int n;
int cnt;
int dy[4] = { -1,1, 0 , 0 };
int dx[4] = { 0,0, -1 , 1 };

vector<string> map;
vector<vector<bool>> visited;
queue<pair<int, int>> q;
vector<int> result;

void Bfs(int y, int x) // Bfs탐색으로 새로운 단지의 집 갯수 알아낸다
{
    q.push(make_pair(y, x));
    visited[y][x] = true;
    cnt++;

    while (q.empty() == false)
    {
        int qY = q.front().first;
        int qX = q.front().second;
        q.pop();

        for (int i = 0; i < 4; i++)
        {
            int nY = qY + dy[i];
            int nX = qX + dx[i];

            if (0 <= nY && 0 <= nX && nY < n && nX < n && visited[nY][nX] == false && map[nY][nX] == '1')
            {
                cnt++;
                visited[nY][nX] = true;
                q.push(make_pair(nY, nX));
            }
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    //freopen("input.txt", "rt", stdin);

    cin >> n; // 맵 사이즈 입력 받아서 map이랑 방문 표시 맵 리사이즈
    map.resize(n);
    visited.resize(n, vector<bool>(n, false));

    for (int i = 0; i < n; i++) // 문자열로 받는게 더 편하게 입력받게 되어있다.
        cin >> map[i];

    for (int y = 0; y < n; y++)
    {
        for (int x = 0; x < n; x++)
        {
            if (map[y][x] == '1' && visited[y][x] == false) // 단지인지 확인 1 이랑 방문했는지 확인해서 BFS돌린다.
            {
                cnt = 0;
                Bfs(y, x);
                result.push_back(cnt); // 새로운 단지에 집 갯수 추가
            }
        }
    }

    cout << result.size() << endl; // 단지 수 출력
    sort(result.begin(), result.end());
    for (int i = 0; i < result.size(); i++)
        cout << result[i] << endl; // 단지별 집 갯수 오름차순 출력


    return 0;
}