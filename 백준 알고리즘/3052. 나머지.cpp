#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<map>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    freopen("input.txt", "rt", stdin); // input.txt 파일 읽기
    map<int, int> m;

    int tmp;
    for (int i = 0; i <= 10; i++)
    {
        cin >> tmp;
        m.insert({ tmp % 42, 1 }); // map은 키 중복 안되서 새로운 나머지 값 나올때만 insert 작동
    }

    cout << m.size(); // 중복된 값이 없기 때문에 세팅된 key값이 나머지 개수

    return 0;
}

