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
    int T, n;
    string s;
    cin >> T;

    for (int i = 0; i < T; i++) // 테스트 개수 T
    {
        cin >> n;
        cin >> s;

        for (int j = 0; j < s.size(); j++)
        {
            for (int h = 0; h < n; h++) // 각 문자를 n번 반복
            {
                cout << s[j];
            }
        }
        cout << "\n";
    }

    return 0;
}
