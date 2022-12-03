#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<algorithm>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    freopen("input.txt", "rt", stdin);
    int N, M;
    cin >> N >> M;

    if (N == 1) // 세로 한칸이면 움직일 수 없다
    {
        cout << 1 << endl;
    }
    else if (N == 2) // 세로가 두 칸이면 2와 3번만 가능
    {
        // 방문칸이 5개 이상이면 모든 이동 방법을 써야하는데 2,3번밖에 쓰지 못해서 최대 4칸으로 제한된다
        cout << min(4, ((M - 1) / 2) + 1) << endl;
    }
    else if (N >= 3) //1, 2, 3, 4번이 적어도 한번씩은 나와야 한다
    {
        //가로가 6까지는 최대 4칸(1번, 4번, 2 or 3번)
        if (M <= 6)
        {
            cout << min(4, M) << endl;
        }
        else //2번 3번 한번씩 나머지는 1번, 4번
        {
            // 가로 2칸 이동 한번 씩 하고 나머진 가로칸만큼 한 칸씩 이동
            cout << M - 2 << endl;
        }
    }

    return 0;
}
