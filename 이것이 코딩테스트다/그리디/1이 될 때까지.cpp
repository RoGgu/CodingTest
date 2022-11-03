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
    int n, k, res = 0;
    cin >> n >> k;

    while (true)
    {
        // n이 k로 나누어 떨어지는 지는 수 구하기
        int target = (n / k) * k;
        // n이 k로 나누어 떠어지는 수 target될 떄가지 1 뺴준 수 카운트
        res += (n - target);
        n = target;

        // k보다 작아지면 나눌 수 없어서 종료
        if (n < k)
            break;

        // n을 k로 나누어준다.
        n = n / k;
        ++res;
    }

    // 나머지 1이 될 때까지 1씩 뺴준 수 카운트 
    res += (n - 1);
    cout << res;

    // 이렇게 n을 한번 씩 확인해서 풀어도 되지만 위에 방식이 nlogn으로 더 빠르다.
    //while (n != 1)
    //{
    //    if (n % k == 0)
    //        n = n / k;
    //    else
    //        n = n - 1;

    //    ++res;
    //}

    return 0;
}