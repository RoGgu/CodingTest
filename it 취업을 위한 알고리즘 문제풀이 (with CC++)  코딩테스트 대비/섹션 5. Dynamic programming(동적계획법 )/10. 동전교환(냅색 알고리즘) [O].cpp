#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<stdio.h>	// cin,cout말고 이제 c에서 제공하는 sanf, printf 사용 - 속도가 조금 더 빠름
#include<vector>
#include<algorithm>

using namespace std;

// 10. 동전교환(냅색 알고리즘)

// 9번과 비슷하게 냅색 알고리즘 적용해서 풀이

// dy[j] j에 해당 잔돈에 거슬러주는 최소 갯수 세팅

int main() {
    ios::sync_with_stdio(false);
    //freopen("input.txt", "rt", stdin);
    int n, m;
    cin >> n;
    vector<int> coin(n);

    for (int i = 0; i < n; i++)
        cin >> coin[i];
    cin >> m;
    vector<int> dy(m + 1, 0);

    for (int i = 0; i < n; i++) // 동전을 한 종류씩 사용해가면서 쌓아간다
    {
        for (int j = coin[i]; j <= m; j++)
        {
            int v = dy[j - coin[i]] + 1; // 동전 새로하나 추가되니까 + 1

            if (dy[j] == 0) // 0이면 아직 세팅안된 값이라서 그냥 세팅
                dy[j] = v;
            else if (v < dy[j]) // 더 적은 갯수로 돌려줘야하니까 더 적을떄만 새로 세팅
                dy[j] = v;
        }
    }

    cout << dy[m];
    return 0;
}