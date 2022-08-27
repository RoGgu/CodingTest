#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<string>
#include<vector>
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
    string s;
    getline(cin, s);
    bool isCheck = false;
    vector<char> reverseChar; // 뒤집어서 표시할 단어 저장할 배열
    char tmp;

    for (int i = 0; i < s.size(); i++)
    {
        if (s[i] == ' ')
        {
            for (int j = reverseChar.size() - 1; j >= 0; j--)
            {
                cout << reverseChar[j];
            }
            cout << " ";
            reverseChar.clear();
        }
        else if (s[i] == '>')
        {
            cout << ">";
            for (int j = reverseChar.size() - 1; j >= 0; j--)
            {
                cout << reverseChar[j];
            }
            reverseChar.clear();
            isCheck = false;
        }
        else if (s[i] == '<')
        {
            for (int j = reverseChar.size() - 1; j >= 0; j--)
            {
                cout << reverseChar[j];
            }
            reverseChar.clear();

            cout << '<';
            isCheck = true;
        }
        else if (isCheck == true)
        {
            cout << s[i];
        }
        else
        {
            reverseChar.push_back(s[i]);
        }
    }

    for (int j = reverseChar.size() - 1; j >= 0; j--) // 남아있는 뒤집을 단어 있으면 뒤집어서 출력
    {
        cout << reverseChar[j];
    }


    return 0;
}
