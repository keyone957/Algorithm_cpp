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
		dp[i] = max(dp[i - 2],//(1) µÎÄ­ ¶Ù¾î i¿¡ ÂøÁö ex ) 4¶ó°í Ä¡¸é 1 2 4
			dp[i - 3] + stair[i-1]//(2) ÇÑÄ­¾¿ 4¶ó°í Ä¡¸é 1 3 4 3¿¬¼Ó °è´Ü ¹â±â ¹æÁö À§ÇØ i-2¸¦ °Ç³Ê¶Ü
			/*
			¿¹½Ã: i = 3ÀÏ ¶§
				(1) µÎ Ä­ ¡æ 3: dp[1] + score[3] = score[1] + score[3]

				(2) ÇÑ Ä­¡æÇÑ Ä­: dp[0] + score[2] + score[3] = 0 + score[2] + score[3]
			*/
		);
		dp[i] += stair[i];
	}
	cout << dp[count];
}