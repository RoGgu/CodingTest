#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<string.h>
#include<vector>
#include<queue>
#include <unordered_map>
#include<algorithm>
using namespace std;

int N, M;
int arr[100010];

void binarySearch(int key)
{
    int start = 0;
    int end = N - 1;
    int mid;

    while (end >= start)
    {
        mid = (start + end) / 2;
        if (arr[mid] == key)
        {
            cout << 1 << "\n";
            return;
        }
        else if (arr[mid] > key)
        {
            end = mid - 1;
        }
        else
        {
            start = mid + 1;
        }
    }
    cout << 0 << "\n";
    return;
}


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    freopen("input.txt", "rt", stdin);

    cin >> N;
    int temp;

    for (int i = 0; i < N; i++)
    {
        cin >> temp;
        arr[i] = temp;
    }

    sort(arr, arr + N);
    cin >> M;
    for (int i = 0; i < M; i++)
    {
        cin >> temp;
        binarySearch(temp);
    }
    return 0;
}