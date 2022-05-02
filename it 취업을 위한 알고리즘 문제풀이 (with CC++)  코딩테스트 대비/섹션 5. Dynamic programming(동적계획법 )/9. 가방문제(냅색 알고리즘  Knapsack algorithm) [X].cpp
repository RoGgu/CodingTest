#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<stdio.h>	// cin,cout말고 이제 c에서 제공하는 sanf, printf 사용 - 속도가 조금 더 빠름
#include<vector>
#include<algorithm>

using namespace std;

// 9. 가방문제(냅색 알고리즘 : Knapsack algorithm)

// 가방에 무게별로 dy배열을 만든다
// dy 배열에 값은 인덱스가 무게로 쳐지고 해당 무게에 보석의 최대가치 값을 담는다.

// 보석을 첫번째부터 사용했을떄에 최대가지 dy배열을 만들고
// - 이떄 시작 배열은 현재 보석이 담기는 가방 무게 즉 현재 보석의 무게부터다
// -- 세팅할떄 방식은 현재 무게에서 보석의 무게를 뺀 dy에 값 + 현재 보석의 값이다. 
// j는 가방 무게, w는 보석 무게, v는 보석 값 =>  (dy[j] =  dy[j - w] +  v)
// 첫번째 보석으로 세팅되어있는 dy값에 그다음 두번쨰 보석값을 적용해서 최대가치 값 dy를 만든다
// 이때 이미 dy값이 있는 무게인덱스일 경우 현재 보석으로 했을때 더 높은 가치일때만 값을 바꾼다.
// 그러면 dy[가방 무게] 에는 담을 수 있는 최대 값어치에 보석 값이 나온다.


int main() {
    ios::sync_with_stdio(false);
    freopen("input.txt", "rt", stdin);
    int n, m, w, v; // n :보석의 갯수, m :가방에 무게제한
    cin >> n >> m;
    vector<int> dy(m + 1, 0);

    for (int i = 0; i < n; i++)
    {
        cin >> w >> v; // 현재 보석에 w : 무게, v : 값어치 를 받는다.

        for (int j = w; j <= m; j++) // 가방에 보석을 한개라도 담을 수 있는 무게부터 시작한다.
        {
            int newValue = dy[j - w] + v; // 현재 보석으로 채울경우 그 무게를 뺀 가방의 dy값 더하고 현재 보석 값
            if (dy[j] < newValue) // 이미 다른 보석으로 채워져있는 값어치가 더 높은경우 새로 세팅하지 않는다.
            {
                dy[j] = newValue;
            }
        }
    }

    cout << dy[m];
    return 0;
}