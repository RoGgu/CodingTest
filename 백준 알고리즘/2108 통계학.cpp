#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<string>
#include<vector>
#include<queue>
#include<algorithm>
#include<cmath>
using namespace std;

vector<int> arr;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    freopen("input.txt", "rt", stdin);
    int num, tmp, range, middle = 0, most_val, mean = 0;
    int most = -9999;
    int number[8001] = { 0, };
    bool not_first = false;
    cin >> num;
    for (int i = 0; i < num; i++)
    {
        cin >> tmp;
        arr.push_back(tmp);
        mean += tmp;
        number[tmp + 4000]++;
    }
    sort(arr.begin(), arr.end());
    for (int i = 0; i < 8001; i++)
    {
        if (number[i] == 0)
            continue;
        if (number[i] == most)
        {
            if (not_first)
            {
                most_val = i - 4000;
                not_first = false;
            }
        }
        if (number[i] > most)
        {
            most = number[i];
            most_val = i - 4000;
            not_first = true;
        }
    }
    middle = arr[arr.size() / 2];
    mean = round((float)mean / num);
    range = arr.back() - arr.front();
    cout << mean << '\n' << middle << '\n' << most_val << '\n' << range;
    return 0;
}
