#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>

using namespace std;


int main() {
    ios::sync_with_stdio(false);
    freopen("input.txt", "rt", stdin);
    int n, k;
    string str;
    deque<int> d; // 삽입 삭제 자주하니까 vector 대신 deque 사용

    cin >> n >> k;
    cin >> str;

    for (int i = 0; i < n; i++)
    {
        // 새로 추가되는 수가 기존 마지막 수보다 큰 경우 삭제하는걸 반복한다
        while (k > 0 && d.empty() == false && d.back() < (str[i] - 48))
        {
            k--;
            d.pop_back();
        }
        // 새로 수 추가
        d.push_back((str[i] - 48));
    }

    // k 빼주는 이유
    // 뒤에 계속 작은수가 와서 중간에 지울게 없어서 k가 남아있을 경우 
    // 최소 k 개의 번호는 지워야하니까 전체 사이즈에서 k 만큼 뺴준다
    for (int i = 0; i < d.size() - k; i++)
        cout << d[i];

    return 0;
}