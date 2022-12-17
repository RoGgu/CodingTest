#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
#include<queue>
#include<map>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    freopen("input.txt", "rt", stdin);
    int N, M;
    map<string, string> m;
    cin >> N >> M;

    for (int i = 0; i < N; i++)
    {
        // 사이트, 비밀번호 쌍을 map으로 저장한다
        pair<string, string> tmp;
        cin >> tmp.first;
        cin >> tmp.second;

        m.emplace(tmp);
    }

    for (int i = 0; i < M; i++)
    {
        string s;
        cin >> s;

        // 사이트 키값에 비밀번호가 기록되어 있다
        cout << m[s] << endl;
    }

    return 0;
}
