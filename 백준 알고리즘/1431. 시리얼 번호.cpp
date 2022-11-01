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

bool Compare(const string& s1, const string& s2)
{
    if (s1.size() == s2.size())
    {
        int sum1 = 0, sum2 = 0;

        for (int i = 0; i < s1.size(); i++)
        {
            if (48 <= s1[i] && s1[i] <= 57)
            {
                sum1 += (s1[i] - 48);
            }

            if (48 <= s2[i] && s2[i] <= 57)
            {
                sum2 += (s2[i] - 48);
            }
        }

        if (sum1 == sum2) // 숫자들 합 같을 경우 사전순으로 정렬
        {
            for (int i = 0; i < s1.size(); i++)
            {
                if (s1[i] == s2[i])
                {
                    continue;
                }
                else
                {
                    return s1[i] < s2[i];
                }
            }
        }
        else
        {
            // 숫자 합을 정렬, 합이 작은게 앞으로 온다
            if (sum1 < sum2)
                return true;
            else
                return false;
        }
    }
    else // 사이즈 다를 경우 적은게 앞으로 온다
    {
        if (s1.size() < s2.size())
            return true;
        else
            return false;
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    freopen("input.txt", "rt", stdin);
    int n;
    cin >> n;
    vector<string> v(n);
    for (int i = 0; i < n; i++)
    {
        cin >> v[i];
    }

    sort(v.begin(), v.end(), Compare); // 정렬적용

    for (int i = 0; i < v.size(); i++)
    {
        cout << v[i] << "\n";
    }

    return 0;
}
