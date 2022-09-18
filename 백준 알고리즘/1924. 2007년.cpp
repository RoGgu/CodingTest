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
    int x, y, totalDay = 0;
    cin >> x >> y;

    int daysInMonth[12] = { 31,28,31,30,31,30,31,31,30,31,30,31 }; // 월 별 날짜 수
    string days[] = { "SUN", "MON", "TUE", "WED", "THU", "FRI", "SAT" }; // 일주일 7일로 해서 총 날짜의 7로 나눳을 때에 요일

    for (int i = 0; i < (x - 1); i++) // x-1 월 까지의 날짜를 다 더한다.
    {
        totalDay += daysInMonth[i];
    }
    totalDay += y; // x읠에 해당하는 y 날짜도 더한다.


    cout << days[totalDay % 7]; // 총 날짜 수 합의 %7이 배열에 해당하는 x월 y일에 요일이다.
    return 0;
}