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
    int n, m, tmp;
    cin >> n;
    map<int, int> chMap;

    for (int i = 0; i < n; i++)
    {
        cin >> tmp;
        chMap.insert(make_pair(tmp, 1));
    }

    cin >> m;
    for (int i = 0; i < m; i++)
    {
        cin >> tmp;
        if (chMap.find(tmp) != chMap.end())
        {
            cout << "1 ";
        }
        else
            cout << "0 ";
    }


    return 0;
}
