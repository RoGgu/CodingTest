#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<vector>
#include<algorithm>
#include<math.h>

using namespace std;

// 수열 공식 구하는 부분을 전혀 생각못했다.
// 풀이보고 코드를 짜서 풀었다.
// 
// 풀이
// 처음 시작거리와 끝 거리는 1로 고정되있어서
// 1 2 3 2 1 이런식으로 최대거리를 구해야한다.
// 거리에 제곱근을 최대 이동할 수 있는 거리로 구하고
// 이동거리 - 최대 이동거리 제곱을 뺀 나머지거리를
// 나머지거리 / 최대이동거리의 값을 올림처리 해줘서 구한다
// 
// 공식
// 최대 이동거리 N , 나머지 거리 A
// 이동거리 = N^2 + A
// 
// 이동 하는데 필요한 횟수는 
// (2N -1) + (A/N)(올림)
// 
// ex) 이동거리가 13이면
// N =3, A =4
// 공식 적용
// (2*3 -1) + (4/3)(올림)
// -> 5 + 2 = 7
// 
// 나중에 다시 풀어보자

// 풀이 사이트
// https://cryptosalamander.tistory.com/25


int main()
{
    //freopen("input.txt", "rt", stdin); // input.txt 파일 읽기
    int n;
    long long x, y, lenght, max, rest, move;
    cin >> n;

    for (int i = 0; i < n; i++)
    {
        cin >> x >> y;
        lenght = y - x; // 가야할 거리
        max = 0;

        while (max * max <= lenght) // 최대 이동거리 구한다.
            max++;
        max--;
        move = (2 * max) - 1; // 최대이동거리로 이동하는 횟수 더해줌

        // 최대이동거리만큼 이동하고 나머지 거리
        rest = lenght - max * max; // 가야할 거리 - 최대이동거리
        rest = (long long)ceil((double)rest / (double)max); // ceil은 반올림 math.h 함수

        // 올림해서 더해준다.
        move += rest;

        cout << move << endl;
    }

    return 0;
}

