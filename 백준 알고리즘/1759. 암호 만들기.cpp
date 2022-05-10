#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>

using namespace std;

int L, C;
vector<char> v;
vector<char> arr;

void DFS(int n)
{
    if (arr.size() == L) // 조합의 갯수 맞는지 체크한다.
    {
        int co = 0; // 자음 갯 수
        int vo = 0; // 모음 갯 수
        for (int i = 0; i < L; i++)
        {
            // 자음 모음 갯수 조건 체크
            if (arr[i] == 'a' || arr[i] == 'e' || arr[i] == 'i' || arr[i] == 'o' || arr[i] == 'u')
                vo++;
            else
                co++;
        }
        if (vo >= 1 && co >= 2)  // 자음 모음 갯수 조건 맞을떄 출력
        {
            for (int i = 0; i < L; i++)
                cout << arr[i];
            cout << endl;
        }
    }
    else
    {
        for (int i = n; i < C; i++)
        {
            arr.push_back(v[i]);
            DFS(i + 1); // 문자열 뒤에 하나 추가하고 뺴주는 식으로 DFS 돌린다.
            arr.pop_back();
        }
    }
}


int main() {
    ios::sync_with_stdio(false);
    freopen("input.txt", "rt", stdin);

    cin >> L >> C;
    v.resize(C);

    for (int i = 0; i < C; i++)
        cin >> v[i];

    sort(v.begin(), v.end()); // 영어사전 순으로 정렬위해서 오름차순 정렬한다.

    DFS(0);

    return 0;
}