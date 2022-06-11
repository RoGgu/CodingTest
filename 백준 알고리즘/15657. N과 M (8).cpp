#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<string.h>
#include<vector>
#include<algorithm>
using namespace std;

int n, m;
vector<int> nums;
vector<int> res;

void DFS(int idx, int cnt)
{

    if (cnt == m)
    {
        for (int i = 0; i < res.size(); i++)
            cout << res[i] << " ";
        cout << "\n";
    }
    else
    {
        for (int i = idx; i < n; i++)
        {
            res.push_back(nums[i]);
            DFS(i, cnt + 1);
            res.pop_back();
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    freopen("input.txt", "rt", stdin);

    cin >> n >> m;
    nums.resize(n);
    for (int i = 0; i < n; i++)
        cin >> nums[i];
    sort(nums.begin(), nums.end());

    DFS(0, 0);
    return 0;
}