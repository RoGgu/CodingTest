#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<queue>
#include<vector>
#include<algorithm>
#include<math.h>
#include<map>

using namespace std;

int main()
{
    freopen("input.txt", "rt", stdin); // input.txt 파일 읽기
    int w, h, cnt;
    map<string, int> map;
    int n, m;
    cin >> n >> m;
    vector<string> res;

    for (int i = 0; i < n; i++)
    {
        string name;
        cin >> name;
        map.insert(make_pair(name, 0)); // 맵 형태로 저장
    }

    for (int i = 0; i < m; i++)
    {
        string name;
        cin >> name;
        if (map.find(name) != map.end()) // 이미 있는 경우 듣도보지 못한사람이라서 정답 배열에 추가
            res.push_back(name);
    }

    cout << res.size() << endl;
    sort(res.begin(), res.end()); // 사전 순으로 출력을 위해 정렬
    for (int i = 0; i < res.size(); i++)
        cout << res[i] << endl;

    return 0;
}

