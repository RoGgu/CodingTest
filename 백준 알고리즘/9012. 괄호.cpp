#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>

using namespace std;


int main() {
    ios::sync_with_stdio(false);
    //freopen("input.txt", "rt", stdin);
    int n;
    cin >> n;

    for (int i = 0; i < n; i++)
    {
        string str;
        cin >> str;
        int check = 0; // '('일 경우 +, ')' 일경우 - 로 서로 짝이 맞는지 체크

        for (int j = 0; j < str.size(); j++)
        {
            if (str[j] == '(')
                check++;
            else if (str[j] == ')')
                check--;

            if (check < 0) // 음수가 되는 순간 ( 보다 )가 더 많아진 상황이니 짝이 맞을 수가 없으니 판별 끝낸다.
                break;
        }

        if (check == 0) // 짝 서로 잘 맞으니 YES
            cout << "YES" << endl;
        else
            cout << "NO" << endl;
    }

    return 0;
}