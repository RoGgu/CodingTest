#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<vector>
#include<stack>

using namespace std;
int main() {
    ios::sync_with_stdio(false);
    freopen("input.txt", "rt", stdin);
    int n, maxArea = 0;
    cin >> n;
    vector<int> h(n + 2, 0); // 맨 처음, 뒤는 0으로 채운다.
    stack<int> s;

    for (int i = 1; i <= n; i++) // 1부터 시작
        cin >> h[i];

    s.push(0); // 높이가 0인걸 기본으로 넣는다.

    for (int i = 1; i <= n + 1; i++) // n+1까지 하는 이유는 히스토리 계속 증가했을 경우 while문 안 돌아서 마지막에 0 넣었다는 가정을 위해
    {
        while (s.empty() == false && h[s.top()] > h[i]) // 기존 높이보다 작은 높이 들어오면, 그높이보다 작거나 같아질때 까지 기존에 있던것들 넓이 계산
        {
            int tmpIdx = s.top(); // 현재 높아서 뺴야하는 막대 인덱스 저장
            s.pop();
            int height = h[tmpIdx]; //  높이
            int width = (i - s.top() - 1); // 가로 길이 - 현재 tmpIdx 인덱스부터 i -1 까지 지금 막대 그래프보다 높이가 낮은건 없어서 전부 가로길이로 계산
            int area = height * width; // 높이 * 너비 = 넓이

            if (area > maxArea) // 최고 넓이 기록
                maxArea = area;
        }

        s.push(i); // 자기보다 높은 막대기 다 빼고나서 자기자신 넣어줌
    }

    cout << maxArea << endl;
    return 0;
}
