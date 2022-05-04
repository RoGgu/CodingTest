#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>   // cin,cout말고 이제 c에서 제공하는 sanf, printf 사용 - 속도가 조금 더 빠름
#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
#include<cstdlib>

using namespace std;

// 11. 최대점수 구하기(냅색 알고리즘)

// 이중 배열로 중복되지 않게 dy값 구하는 방식이 있지만
// 이 방식보다는 뒤에서 부터 dy값 세팅하는 방식으로 해서 
// 중복되지 않는 1차원 배열로 dy값을 세팅한다.

struct Problem
{
    Problem() {};
    Problem(int v, int t)
    {
        value = v;
        time = t;
    }


    int value;
    int time;

    bool operator<(const Problem& p) const
    {
        return value < p.value;
    }

};

int main()
{
    //freopen("input.txt", "rt", stdin); // input.txt 파일 읽기
    int n, m, v, t;
    cin >> n >> m;
    vector<Problem> vP(n);
    vector<int> dy(m + 1, 0);

    for (int i = 0; i < n; i++)
    {
        cin >> v >> t;
        vP[i] = Problem(v, t);
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = m; j >= vP[i].time; j--) // 중복되지 않도록 뒤에서부터 더 하는 식으로 dy값을 세팅한다
        {
            int newValue = dy[j - vP[i].time] + vP[i].value;
            if (newValue > dy[j])
                dy[j] = newValue;

        }
    }

    cout << dy[m];
    return 0;
}


// 2차원 배열로 푸는 방식
// 근데 값이 많아지면 메모리와 속도를 엄청 잡아먹어서
// 실제로 이런식으로 풀지 않고 일차원 배열로 푼다
// 
//int main()
//{
//    //freopen("input.txt", "rt", stdin); // input.txt 파일 읽기
//    int n, m, v, t;
//    cin >> n >> m;
//    vector<Problem> vP(n + 1);
//    vector<vector<int>> dy(n + 1, vector<int>(m + 1));
//
//
//    vP[0] = Problem(0, 0);
//    for (int i = 1; i <= n; i++)
//    {
//        cin >> v >> t;
//        vP[i] = Problem(v, t);
//    }
//
//    sort(vP.begin(), vP.end());
//
//    for (int i = 1; i <= n; i++)
//    {
//        for (int j = 0; j <= m; j++)
//        {
//            dy[i][j] = dy[i - 1][j];
//        }
//
//        for (int j = vP[i].time; j <= m; j++)
//        {
//            int newValue = dy[i - 1][j - vP[i].time] + vP[i].value;
//            if (newValue > dy[i][j])
//                dy[i][j] = newValue;
//
//
//        }
//    }
//
//    cout << dy[n][m];
//
//    return 0;
//}
