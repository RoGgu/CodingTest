#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
#include<map>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    freopen("input.txt", "rt", stdin);
    int T, N;
    long long res = 1;
    string name, type;
    map<string, int> m;
    cin >> T;

    for (int t = 0; t < T; t++)
    {
        res = 1;
        m.clear();
        cin >> N;
        for (int i = 0; i < N; i++)
        {
            cin >> name >> type;

            auto tmp = m.find(type);

            // map 같은경우 인덱스 [] 에 접근만 해도 바로 Key랑 Value값이 세팅되지만 확실히 하기 위해 해당 타입이 없으면 1을 넣어준다.
            if (tmp != m.end())
            {
                tmp->second += 1;
            }
            else
            {
                m.emplace(make_pair(type, 1));
            }
        }

        for (auto tmp : m)
        {
            // 해당 타입에 의상 개수 만큼 곱해주는데 모든 의상을 안 입는 경우가 있어서 +1 해준다
            // 예를들어 같은 의상이 3개가 있으면 3개를 입는 경우 + 안입는 경우로 총 4가지의 경우의 수가이다
            res *= (tmp.second + 1);
        }

        // 모든 타입에 의상들을 다 안 입어서 알몸인 경우 한 가지를 뺀다
        res -= 1;

        cout << res << endl;
    }

    return 0;
}
