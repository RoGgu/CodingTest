#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<stdio.h>	// cin,cout말고 이제 c에서 제공하는 sanf, printf 사용 - 속도가 조금 더 빠름
#include<vector>
#include<algorithm>

using namespace std;

// 가장 높은 탑 쌓기(LIS응용)

// 벽돌 구조체하나 만들어서 vector로 관리
// 밑면을 기준으로 오름차순 정렬을한다.
// 처음부터 돌면서 자기 자신을 제일 밑으로 했을때 자기 위에 올 벽돌에 dy값을 더하는 식으로 진행

// 강사는 내림차순으로 했는데 사실 풀이는 똑같다.

struct Block
{
    Block() {    }

    Block(int b, int h, int w) // 밑면, 높이, 무게 세팅
    {
        bottom = b;
        height = h;
        weight = w;
    }

    bool operator<(const Block& b) const // 밑면이 작은거부터 우선으로오게 오름차순 정렬
    {
        return bottom < b.bottom; // 앞에 자리가 작고 뒷 자리가 크다 (오름차순)
        //return bottom > b.bottom; // 앞에 자리가 크고 뒷 자리가 작다 (내림차순)
    }

    int bottom;
    int height;
    int weight;
};

int main() {
    //freopen("input.txt", "rt", stdin);
    cin.tie(NULL);
    ios::sync_with_stdio(false);
    int n, b, h, w, result = 0;
    cin >> n;
    vector<Block> v(n);
    vector<int> dy(n);

    for (int i = 0; i < n; i++)
    {
        cin >> b >> h >> w;
        v[i] = Block(b, h, w);
    }

    sort(v.begin(), v.end());
    dy[0] = v[0].height; // 처음 벽돌의 dy값은 자기 자신높이
    result = dy[0]; // 처음 벽돌 값 결과로 세팅

    for (int i = 1; i < n; i++)
    {
        int max_h = 0;
        for (int j = i - 1; j >= 0; j--)
        {
            if (v[j].weight < v[i].weight && dy[j] > max_h) // 자기 바로 위에 올 애를 찾는다, 근데 dy값이 가장 큰애
            {
                max_h = dy[j];
            }
        }

        max_h += v[i].height; // 자기 바로위에 올애에 dy값 + 자기자신 높이
        dy[i] = max_h;
        if (dy[i] > result) // 제일 큰 높이가 답
            result = dy[i];
    }

    cout << result << endl;
    return 0;
}