#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<string.h>
#include<vector>
#include<queue>
#include <unordered_map>
#include<algorithm>
using namespace std;

int cmp(string a, string b) {
	if (a.length() == b.length()) // 길이 같으면 사전순 
		return a < b;
	else
		return a.length() < b.length(); // 길이 다르면 짦은거
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	freopen("input.txt", "rt", stdin);
	int N;
	cin >> N;
	vector<string> words(N);
	for (int i = 0; i < N; i++)
	{
		cin >> words[i];
	}

	sort(words.begin(), words.end(), cmp);
	cout << words[0] << "\n";
	for (int i = 1; i < N; i++)
	{
		if (words[i] == words[i - 1]) // 전 단어랑 같으면 중복된 거라 출력 안함
			continue;
		cout << words[i] << "\n";
	}
	return 0;
}