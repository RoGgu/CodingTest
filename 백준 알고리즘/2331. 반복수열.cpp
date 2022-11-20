#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<algorithm>
#include<cmath>
#include<map>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n, p, len = 0, cnt = 0;
    cin >> n >> p;
    long long prevNum = n;
    map<long long, int> chMap; // [해당 수], [해당 수가 나올 떄 까지 나열된 숫자 개수]

    chMap[n] = 0;

    while (true)
    {
        long long num = 0;

        while (prevNum > 0)
        {
            // 각 일의자리 p만큼 곱해서 숫자를 구한다
            num += pow((prevNum % 10), p);
            prevNum = prevNum / 10;
        }

        if (chMap.find(num) != chMap.end())
        {
            // 중복 되는게 처음 발견 순간 그 전까지가 중복되지 않는 수열 
            cnt = chMap[num]; // 해당 수열 발견되기 전 까지에 총 수 개수가 세팅되어 있다
            break;
        }

        len++;
        chMap[num] = len;
        prevNum = num;
    }

    cout << cnt;
    return 0;
}
