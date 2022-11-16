#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<string>

using namespace std;

bool fail[1000];

void Check(string str, int strike, int ball)
{
    // str에 경우 나오는 스타라이크와 볼 개수를 토대로 123~987까지 체크해서 스트라이크 볼 개수 다를경우 제외한다

    string tmp = str;
    int tmpSt = 0;
    int tmpBa = 0;

    for (int i = 123; i < 988; i++)
    {
        if (fail[i] == true) // 이미 제외된 수라면 패스
            continue;

        tmpSt = 0;
        tmpBa = 0;
        tmp = to_string(i);

        for (int j = 0; j < 3; j++)
        {
            for (int k = 0; k < 3; k++)
            {
                if (tmp[j] == str[k])
                {
                    // 자릿 수의 값이 같을 경우 같은 자리수면 스트라이크, 아니면 볼 개수를 증가시킨다
                    if (j == k)
                    {
                        tmpSt++;
                    }
                    else
                    {
                        tmpBa++;
                    }
                }
            }
        }

        // 현재 tmp랑 str 케이스에 스트라이크. 볼 개수가 다르면 제외되어야 할 숫자이다
        if (tmpSt != strike || tmpBa != ball)
        {
            fail[i] = true;
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    freopen("input.txt", "rt", stdin);
    int n, a, b, res = 0;
    string tmp;
    cin >> n;

    for (int i = 0; i < n; i++)
    {
        cin >> tmp >> a >> b;
        Check(tmp, a, b);
    }

    // 0을 포함하지 않기 위해 각 자리수 1~9까지 해서 구한다
    // 이 때 중복되면 안되기 떄문에 예외처리 적용
    int num = 0;
    for (int i = 1; i < 10; i++)
    {
        for (int j = 1; j < 10; j++)
        {
            if (i == j)
                continue;

            for (int k = 1; k < 10; k++)
            {
                if (k == i || k == j)
                    continue;

                num = (i * 100) + (j * 10) + k;

                // Check 케이스에서 제외되지 않는 수는 경우의 수가 될 수 있기 때문에 개수 증가
                if (fail[num] == false)
                {
                    res++;
                }
            }
        }
    }

    cout << res;
    return 0;
}
