#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<string>
#include<algorithm>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int T;
	cin >> T;

	int dy[4] = { -1,0,1,0 }; //북 동 남 서 방향
	int dx[4] = { 0,1,0,-1 };

	for (int i = 0; i < T; i++)
	{
		int cY = 0, cX = 0, dir = 0;
		int minX = 0, minY = 0, maxX = 0, maxY = 0;

		string arr;
		cin >> arr;

		for (int j = 0; j < arr.size(); j++)
		{
			if (arr[j] == 'F')
			{
				// 앞으로 이동
				cY = dy[dir] + cY;
				cX = dx[dir] + cX;
			}
			else if (arr[j] == 'B')
			{
				// 뒤로 이동이니까 반대 방향으로 이동
				cY = dy[(dir + 2) % 4] + cY;
				cX = dx[(dir + 2) % 4] + cX;
			}
			else if (arr[j] == 'R')
			{
				// 우측으로 회전
				dir = (dir + 1) % 4;
			}
			else if (arr[j] == 'L')
			{
				// 좌측으로 회전
				dir--;
				if (dir < 0)
				{
					dir += 4;
				}
			}

			// 넓이 구하기 위해서 큰 값, 작은 값 세팅
			if (maxX < cX)
			{
				maxX = cX;
			}
			if (maxY < cY)
			{
				maxY = cY;
			}
			if (minX > cX)
			{
				minX = cX;
			}
			if (minY > cY)
			{
				minY = cY;
			}
		}

		// 넓이 출력
		cout << ((maxY - minY) * (maxX - minX)) << "\n";
	}
	return 0;
}
