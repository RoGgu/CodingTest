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
    ios::sync_with_stdio(false);
    freopen("input.txt", "rt", stdin); // input.txt 파일 읽기
    int t;
    cin >> t;

    for (int i = 0; i < t; i++)
    {
        int k;
        cin >> k;
        multiset<int> m;

        for (int n = 0; n < k; n++)
        {
            char c;
            int num;
            cin >> c >> num;

            if (c == 'I') // I일 경우 삽입
            {
                m.insert(num); // multiset이 오름차순으로 잘 넣어준다.
            }
            else if (c == 'D') // num값에 따라서 최솟값 혹은 최댓값 삭제한다.
            {
                if (m.empty())
                    continue;

                if (num == -1) // 최솟값 삭제
                {
                    m.erase(m.begin());
                }
                else if (num == 1) // 최댓값 삭제
                {
                    m.erase(--(m.end())); // end() 앞에꺼가 마지막 값이니까 그거 삭젠
                }
            }
        }

        if (m.empty())
            cout << "EMPTY" << endl;
        else
            cout << *(--(m.end())) << " " << *(m.begin()) << endl;
    }
}