#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<string>
#include<vector>
#include <unordered_set>
using namespace std;

int n, k, res = 0;
int arr[11];
int arrCh[11];
vector<int> v; // 카드 나열 목록
unordered_set<string> resultSet;

void DFS()
{
    if (v.size() == k)
    {
        string s = "";

        for (int i = 0; i < v.size(); i++)
        {
            s += to_string(v[i]); // 카드 숫자 더하는게 아닌 나열하는거라 string으로 체크
        }

        resultSet.insert(s); // 중복 값 자동으로 제거하는 unordered_set으로 조합 가능한 수 세팅 (unordered_set인 이유는 정렬 필요 없어서)
    }
    else
    {
        for (int i = 0; i < n; i++)
        {
            if (arrCh[i] == 0) // 사용 안한 카드면 나열 목록에 추가
            {
                arrCh[i] = 1;
                v.push_back(arr[i]);
                DFS();
                arrCh[i] = 0;
                v.pop_back();
            }
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    freopen("input.txt", "rt", stdin);
    cin >> n >> k;
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    DFS();

    cout << resultSet.size(); // 중복 제거되고 세팅된 수들에 갯 수가 카드 조항으로 나올 수 있는 정답이다
    return 0;
}
