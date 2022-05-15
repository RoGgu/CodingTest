#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>

using namespace std;

// 현재 파이브가 몇개 들고있는지 n으로 체크하고 
// 레이저 쏘면 현재 파이브 개수만큼 조각 생기는거고
// ')' 으로 파이브 끝나는 파이프 조각 하나 추가하는 식으로 풀이

int main() {
    ios::sync_with_stdio(false);
    //freopen("input.txt", "rt", stdin);
    string s;
    cin >> s;
    int n = 0, res = 0; // n은 현재 파이브 연장되고있는 개수
    char lc;
    // 처음거는 미리 세팅
    lc = s[0];
    n++;

    for (int i = 1; i < s.size(); i++) // 처음꺼 제외하고 전체 문자 체크
    {
        if (s[i] == ')') // ')' 일경우 이게 레이저 쏘는건지 파이브 하나 끝나느건지 체크
        {
            n--; // '('일떄 파이프로 생각해서 현재 파이브 개수 증가시켰으니까 하나 뺸다.
            if (lc == '(') // 레이저일 경우 현재 파이브만큼 개수 더한다
                res += n;
            else
                res++; // 레이저 아니면 파이브 하나 끝난거니 하나 증가시킴
        }
        else
            n++; // '('일 경우 레이저인지 파이브시작인진 모르지만 일단 파이브 길이로 증가시킨다.

        lc = s[i]; // 다음에서 레이저인지 체크하기위해 저장
    }

    cout << res << endl; // 총 파이브 조각 수 
    return 0;
}