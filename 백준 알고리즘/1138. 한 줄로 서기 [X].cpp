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

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    freopen("input.txt", "rt", stdin);
    int N, left;
    cin >> N;
    int arr[10] = { 0 }; // 0은 빈자리

    // 키가 1부터 시작해서 왼쪽에 몇명있는지 입력을 받는다
    // 키가 1부터 시작하니 왼쪽에 키큰 사람에 숫자만큼 한칸 씩 오른족으로 가는데 이미 다른 사람이 자리에 있는 경우 오른쪽으로 한 칸 더 간다.
    for (int i = 0; i < N; i++)
    {
        cin >> left;

        for (int j = 0; j < N; j++)
        {
            if (left == 0 && arr[j] == 0) // 왼쪽에 키가 큰사람이 있는만큼 오른쪽을 이동하다가 빈자리 있으면 그자리에 세팅
            {
                arr[j] = i + 1;
                break;
            }
            else if (arr[j] == 0) // 이미 다른 사람이 자리에 있는경우 카운트 하지 않는다
            {
                --left;
            }
        }
    }

    for (int i = 0; i < N; i++)
    {
        cout << arr[i] << " ";
    }

    return 0;
}
