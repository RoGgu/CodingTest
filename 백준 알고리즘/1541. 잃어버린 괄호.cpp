#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<queue>
#include<vector>
#include<algorithm>
#include<math.h>
#include<map>
#include<set>
#include<string.h>

using namespace std;


int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    std::cout.tie(NULL);
    freopen("input.txt", "rt", stdin); // input.txt 파일 읽기
    string s;
    cin >> s;
    int res = 0;
    int num = 0;
    int index = 0;
    char c = s[0];
    bool isMinus = false;

    while (c != '\0')
    {
        if (c >= 48 && c <= 57)
        {
            // 숫자일 경우 숫자 저장
            num = (num * 10) + (c - 48);
        }
        else
        {
            // 부호가 마이너스 한번이라도 나오면 그 뒤 숫자는 전부 -로 할 수 있다.
            if (isMinus == true)
                res -= num;
            else
                res += num;

            // 숫자 초기화
            num = 0;

            if (c == '-')
                isMinus = true;
        }

        index++;
        c = s[index];
    }

    // 마지막 숫자 체크
    if (isMinus == true)
        res -= num;
    else
        res += num;

    std::cout << res;
    return 0;
}