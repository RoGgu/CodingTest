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

struct Info
{
    Info(string n, int d, int m, int y)
    {
        name = n;
        day = d;
        month = m;
        year = y;
    }
    string name;
    int day;
    int month;
    int year;
};

bool compare(const struct Info& x, const struct  Info& y)
{
    if (x.year < y.year)
    {
        return true;
    }
    else if (x.year == y.year)
    {
        if (x.month < y.month)
        {
            return true;
        }
        else if (x.month == y.month)
        {
            if (x.day < y.day)
                return true;
            else
                return false;
        }
        else
            return false;
    }
    else
        return false;
}


int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    freopen("input.txt", "rt", stdin);
    int n;
    cin >> n;
    vector<Info> v;
    string name;
    int day;
    int month;
    int year;

    for (int i = 0; i < n; i++)
    {
        cin >> name >> day >> month >> year;
        Info info(name, day, month, year);
        v.push_back(info);
    }

    sort(v.begin(), v.end(), compare); // 나이 많은 사람이 0으로 오도록 sort


    cout << v[n - 1].name << "\n" << v[0].name; // 나이 많은 사람과 적은 사람 이름 출력
    return 0;
}
