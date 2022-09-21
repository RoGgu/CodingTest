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
    int n, res = 0;
    cin >> n;
    vector<int> dy(n + 1, 2147000000); // 다이나믹 탐색을 위해 인덱스에 해당하는 수까지 오는데 거린 최소 계산횟수를 세팅한다.
    vector<int> prevPath(n + 1); // 인덱스에 해당 인덱스 수에 오기전 계산 한 수를 넣어둔다.
    vector<int> resPath; // 정답 출력을 위해 prevPath를 1부터 타고 올라가서 n까지의 수들을 저장해서 뒤집어서 출력하기위해 저장

    queue<pair<int, int>> q; // 계산횟수, 현재 값 을 q에 넣는다.

    q.push(make_pair(0, n));
    while (!q.empty())
    {
        int curCnt = q.front().first;
        int curNum = q.front().second;
        q.pop();

        if (curCnt > dy[curNum])
            continue;

        if (curNum == 1)
        {
            res = curCnt;
            break;
        }


        if (curNum % 3 == 0 && curNum / 3 != 0) // 3으로 나눠지는 경우
        {
            if (curCnt + 1 < dy[curNum / 3]) // dy에 이미 3으로 나누 값이 있으면 비교해서 현재 계산으로 온게 더 적으면 세팅한다.
            {
                dy[curNum / 3] = curCnt + 1;
                prevPath[curNum / 3] = curNum; // 계산해서 세팅하기 전에 수를 prevPath에 저장한다, 나중에 경로 출력하기 위해서
                q.push(make_pair(curCnt + 1, curNum / 3));
            }
        }

        if (curNum % 2 == 0 && curNum / 2 != 0) // 2로 나눠지는 경우
        {
            if (curCnt + 1 < dy[curNum / 2])
            {
                dy[curNum / 2] = curCnt + 1;
                prevPath[curNum / 2] = curNum;
                q.push(make_pair(curCnt + 1, curNum / 2));
            }
        }

        if (curCnt + 1 < dy[curNum - 1]) // -1로 계산한 경우
        {
            dy[curNum - 1] = curCnt + 1;
            prevPath[curNum - 1] = curNum;
            q.push(make_pair(curCnt + 1, curNum - 1));
        }
    }


    cout << res << "\n"; // 최소 계산횟수 출력
    resPath.push_back(1); // 경로 마지막에 1이 나와야 하니 1도 넣어준다.
    int tmp = 1;
    for (int i = 0; i < res; i++)
    {
        resPath.push_back(prevPath[tmp]); // 1부터 경로 꺼구로 n까지 타고 올라가는 수들을 저장한다.
        tmp = prevPath[tmp];
    }

    // 뒤집어서 출력
    for (int i = resPath.size() - 1; i >= 0; i--)
        cout << resPath[i] << " ";

    return 0;
}