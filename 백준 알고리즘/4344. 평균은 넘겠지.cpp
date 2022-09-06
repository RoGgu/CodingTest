#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<string.h>
#include<vector>
#include<queue>
#include <unordered_map>
#include<algorithm>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    freopen("input.txt", "rt", stdin);
    int n, m, res = 0;
    int trueNum; // 진실 아는 사람 수

    cin >> n >> m;
    cin >> trueNum;
    if (trueNum == 0) // 진실 아는 사람 한명도 없으면 파티 전체에 마다 거짓말 가능해서 바로 리턴
    {
        cout << m << "\n";
        return 0;
    }

    vector<int> ch(n + 1, 0); // 인덱스 값이 1일 경우 그사람은 진실 아는 사람이다.
    for (int i = 0; i < trueNum; i++)
    {
        int tNum;
        cin >> tNum;
        ch[tNum] = 1;
    }

    vector<vector<int>> map(m); // 전체 파티 정보 저장
    queue<vector<int>> q; // 진실 모르는 사람 중에서 진실 아는사람 한명이라도 있는 배열인 경우 넣는다

    for (int i = 0; i < m; i++)
    {
        int pN = 0;
        cin >> pN;
        vector<int> pv;

        int tN = 0;
        for (int j = 0; j < pN; j++)
        {
            int tmp;
            cin >> tmp;
            pv.push_back(tmp);
            if (ch[tmp] == 1)
                tN += 1;
        }

        map[i] = pv;

        if (tN > 0 && tN != pv.size()) // 파티 사람중에 전체 다 진실을 알지 않고 진실 아는사람 한명 있을경우 넣어줌
            q.push(pv);
    }

    while (!q.empty())
    {
        vector<int> tmpV = q.front();
        q.pop();
        for (int i = 0; i < tmpV.size(); i++) // 이제 모르는 사람도 진실 다 알게되도록 설정
            ch[tmpV[i]] = 1;


        for (int i = 0; i < m; i++)
        {
            bool isFind = false;
            for (int j = 0; j < tmpV.size(); j++)
            {
                auto it = find(map[i].begin(), map[i].end(), tmpV[j]);
                if (it != map[i].end()) // 파티에 진실 아는사람 한명이라도 있는경우
                {
                    isFind = true;
                    break;
                }
            }

            if (isFind == true)
            {
                int tN = 0;
                for (int j = 0; j < map[i].size(); j++)
                {
                    if (ch[map[i][j]] == 1)
                        tN += 1;
                }
                if (tN != map[i].size()) // 진실 모르는 사람이 있을경우에만 넣어준다.
                    q.push(map[i]);
            }
        }
    }

    for (int i = 0; i < map.size(); i++)
    {
        bool isTrue = false;
        for (int j = 0; j < map[i].size(); j++)
        {
            if (ch[map[i][j]] == 1)
            {
                isTrue = true;
                break;
            }
        }
        if (isTrue == false) // 파티에 참가한 사람이 다 진실 몰라야 거짓말 가능
            res += 1;
    }

    cout << res << "\n";
    return 0;
}