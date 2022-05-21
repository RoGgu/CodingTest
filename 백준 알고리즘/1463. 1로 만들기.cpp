#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    freopen("input.txt", "rt", stdin);
    int X, maxCnt = 2147000000;
    cin >> X;
    vector<int> dy(X + 1, 0);

    // 2와 3일 경우 나누기 한번씩으로 바로 답이나온다.
    dy[2] = 1;
    dy[3] = 1;

    for (int i = 4; i <= X; i++)
    {
        dy[i] = 1 + dy[i - 1]; // 일단 -1 했을떄 값 세팅
        if (i % 3 == 0)
            dy[i] = min(dy[i], 1 + dy[i / 3]); // -1햇을때랑 3으로 나눳을떄에 dy값 + 한번더 계싼하니까 1 더해준거랑 비교해서 작은거 세팅
        if (i % 2 == 0)
            dy[i] = min(dy[i], 1 + dy[i / 2]); // -1햇을때랑 2으로 나눳을떄에 dy값 + 한번더 계싼하니까 1 더해준거랑 비교해서 작은거 세팅
    }

    cout << dy[X] << endl;
    return 0;
}