#define _CRT_SECURE_NO_WARNINGS
#include<iostream>

using namespace std;

int res[3]; // -1, 0 , 1순으로 개수 저장
int graph[2200][2200];

bool check(int row, int col, int num)
{
    // 현재 num 단위 만큼에 종이 값이 다 같은수인지 체크
    int start = graph[row][col];
    for (int i = row; i < row + num; i++)
    {
        for (int j = col; j < col + num; j++)
        {
            if (start != graph[i][j])
            {
                return false;
            }
        }
    }

    return true;
}

void divide(int row, int col, int num)
{
    if (check(row, col, num))
    {
        // 현재 단위에 종이 값이 다 같을 경우 해당 단위 값 개수 증가
        // -1, 0, 1의 값을 +1해서 인덱스 0번부터 저장
        res[(graph[row][col] + 1)]++;
    }
    else
    {
        int size = num / 3;

        // 값이 다를경우 9분할로 나눠서 다시 다시 검사
        for (int i = 0; i < 3; i++)
        {
            for (int j = 0; j < 3; j++)
            {
                divide(row + (size * i), col + (size * j), size);
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
    int N, now;
    cin >> N;
    now = N;

    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            cin >> graph[i][j];
        }
    }

    divide(0, 0, N);

    for (int i = 0; i < 3; i++)
    {
        // -1, 0, 1 순으로 저장된 종이 수 출력
        cout << res[i] << "\n";
    }
    return 0;
}
