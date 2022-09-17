#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<queue>
#include<vector>
#include<algorithm>
#include<math.h>
#include<map>
#include<set>

using namespace std;


int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    freopen("input.txt", "rt", stdin); // input.txt 파일 읽기
    long long N, res = 0, sum = 0, tmp = 1;
    cin >> N;


    // 서로 다른 자연수의 최대 개수를 구할려면 1부터 더해야 한다.
    // 1부터 더해가던 중 N을 넘을 경우 현재 까지 더한 개수 -1이 정답이다.
    // ex) 200을 구한다고 하면 1~20까지의 합은 210으로 더한 수는 20개인데 개수 한개(20)을 빼고 19를 29로 바꾸면 200을 만드는 수 있는 방식으로 구할 수 있다.
    while (true)
    {
        sum += tmp;
        ++tmp;

        if (sum > N)
            break;
        else
            ++res;
    }

    cout << res;
    return 0;
}