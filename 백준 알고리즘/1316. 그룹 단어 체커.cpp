#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<string>
#include<vector>
#include<queue>
#include<algorithm>
#include<cmath>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    freopen("input.txt", "rt", stdin);
    int N, res = 0;
    cin >> N;

    for (int i = 0; i < N; i++)
    {
        bool isCheker = true;
        string s;
        cin >> s;

        vector<int> ch(26, 0); // 소문자만 나와서 아스키 코드 값 97 뺴서 0부터 25까지알파벳 체크 배열 세팅
        char prv = s[0];
        ch[s[0] - 97] = 1;

        for (int j = 1; j < s.size(); j++)
        {
            if (prv != s[j]) // 연속 되지 않을 경우 새로운 단어인지 이미 있는 단어인지 체크
            {
                if (ch[s[j] - 97] == 1) // 전 단어랑 다른데 이미 단어가 나온적이 있다면 그룹 단어 체커가 아니다.
                {
                    isCheker = false;
                    break;
                }

                ch[s[j] - 97] = 1; // 단어 처음 나와서 세팅
            }

            prv = s[j];
        }

        if (isCheker)
            res++;
    }

    cout << res;
    return 0;
}
