#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>

using namespace std;

// s 기존 문자열
// b 폭탄 터지는 문자열

// res에 s문자열 하나씩 추가하면서
// b사이즈 수 즉 폭탄 문자열이 될 수 있는 사이즈 넘어가면
// 마지막 추가할떄마다 b문자열 마지막 문자부터 앞으로 돌면서 체크
// 폭탄 문자열이면 그 문자열들 제거
// 그런식으로 하나씩 추가

int main() {
    ios::sync_with_stdio(false);
    freopen("input.txt", "rt", stdin);
    string s, b;
    cin >> s >> b;
    vector<char> res;

    for (int i = 0; i < s.size(); i++)
    {
        res.push_back(s[i]);

        while (res.size() >= b.size() && res.back() == b.back()) // 새로 추가한 문자열이 폭탄 문자열 끝과 같으면 폭탄 문자열 되는지 체크
        {
            bool isBoom = true;
            for (int j = b.size() - 1; j >= 0; j--)
            {
                if (b[j] != res[res.size() + j - b.size()])
                {
                    // 하나라도 틀린거 있음녀 폭탄 문자열 아니라서 패스
                    isBoom = false;
                    break;
                }
            }

            if (isBoom == true) // 폭탄 문자열이면 그 문자열 지운다.
            {
                for (int j = 0; j < b.size(); j++)
                    res.pop_back();
            }
            else
                break;
        }
    }

    if (res.empty()) // 문자열 남아있지 않으면 FRULA 출력
        cout << "FRULA" << endl;
    else
    {
        for (int i = 0; i < res.size(); i++) // 문자열 남은거 출력
            cout << res[i];
    }

    return 0;
}