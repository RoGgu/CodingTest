#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    freopen("input.txt", "rt", stdin);
    int T, N, M, cnt;
    cin >> T;
    vector<int> A;
    vector<int> B;

    for (int i = 0; i < T; i++)
    {
        cnt = 0;
        cin >> N >> M;
        A.resize(N);
        B.resize(M);

        for (int i = 0; i < N; i++)
        {
            cin >> A[i];
        }
        sort(A.begin(), A.end()); // A배열을 오름차순으로 정렬한다.

        for (int i = 0; i < M; i++)
        {
            cin >> B[i];

            for (int j = 0; j < A.size(); j++)
            {
                if (A[j] > B[i])
                {
                    // A의 수가 더 큰 순간 그 뒤에 수도 다 현재 B[i]보다 크기 떄문에 먹히는 짝이 되어서 남은 수 만큼 카운트한다
                    cnt += A.size() - j;
                    break;
                }
            }
        }

        cout << cnt << "\n";
    }

    return 0;
}
