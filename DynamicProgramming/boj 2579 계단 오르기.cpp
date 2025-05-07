#include <algorithm>
#include <deque>
#include <functional>
#include <iostream>
#include <iterator>
#include <list>
#include <map>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <string>
#include <vector>
using namespace std;
int dp[301];
int stair[301];
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int count;
	cin >> count;
	for (int i = 1; i <= count; i++)
	{
		int stairPoint;
		cin >> stairPoint;
		stair[i] = stairPoint;
	}
	dp[0] = 0;
	dp[1] = stair[1];
	dp[2] = stair[1] + stair[2];
	for (int i = 3; i <= count; i++)
	{
		dp[i] = max(dp[i - 2],//(1) ��ĭ �پ� i�� ���� ex ) 4��� ġ�� 1 2 4
			dp[i - 3] + stair[i-1]//(2) ��ĭ�� 4��� ġ�� 1 3 4 3���� ��� ��� ���� ���� i-2�� �ǳʶ�
			/*
			����: i = 3�� ��
				(1) �� ĭ �� 3: dp[1] + score[3] = score[1] + score[3]

				(2) �� ĭ���� ĭ: dp[0] + score[2] + score[3] = 0 + score[2] + score[3]
			*/
		);
		dp[i] += stair[i];
	}
	cout << dp[count];
}