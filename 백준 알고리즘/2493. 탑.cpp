#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<vector>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    freopen("input.txt", "rt", stdin);
    int n;
    cin >> n;
    vector<int> v;
    vector<int> res(n + 1, 0); // 탑 송신 인덱스 저장
    int max = 0;

    v.push_back(0);
    for (int i = 1; i <= n; i++)
    {
        int temp;
        cin >> temp;
        v.push_back(temp);

        int index = i - 1;
        while (index > 0) // 현재 탑부터 앞으로 체크
        {
            if (v[index] > v[i]) // 자기보다 크면 송신탑으로 인식하고 종료
            {
                res[i] = index;
                break;
            }
            else
            {
                index = res[index]; // 자기보다 작으면 그 탑이 송신하는 더 큰 탑을 바로 찾음
            }
        }

    }

    for (int i = 1; i <= n; i++)
        cout << res[i] << " ";
    return 0;
}
