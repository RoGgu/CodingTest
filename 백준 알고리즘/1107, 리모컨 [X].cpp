#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>
#include<stack>
#include<math.h>
#include <string>

using namespace std;


bool brokentBtn[10]; // 사용 불가능한 버튼은 true로 체크

bool Check(int num)
{
    if (num == 0) //0일 경우 버튼 사용 가능한지 바로 체크해서 리턴
        return !brokentBtn[0];

    while (num > 0) // 한자리씩 버튼 확인하면서 다 가능한지 체크한다
    {
        int idx = num % 10;
        num = num / 10;
        if (brokentBtn[idx] == true) // 하나라도 버튼 사용 못하면 입력할 수 없는 채널
            return false;
    }
    return true;
}

int main() {
    ios::sync_with_stdio(false);
    freopen("input.txt", "rt", stdin);
    int n, m, tmp, minCount;
    cin >> n >> m;
    for (int i = 0; i < m; i++) // 사용 불가능한 버튼 true로 체크
    {
        cin >> tmp;
        brokentBtn[tmp] = true;
    }

    minCount = abs(n - 100); // 현재 채널 100에서 +,- 버튼만 사용했을때 버튼 입력 개수

    for (int i = 0; i <= 1000000; i++) // 모든 채널을 입력할 수 있는지 체크한다.
    {
        if (Check(i) == true) // 버튼으로 그 채널 입력 가능하면
        {
            int cnt = abs(n - i); // 그 채널까지에 +,- 버튼 입력 수
            tmp = i;
            // 이제 채널 입력할때 숫자 버튼 입력 수를 더한다
            if (tmp == 0) // 0이면 0번 한번 입력이니까 1
                cnt++;
            else
            {
                while (tmp > 0)
                {
                    tmp = tmp / 10;
                    cnt++;
                }
            }
            minCount = min(minCount, cnt);
        }
    }

    cout << minCount << endl;
    return 0;
}


