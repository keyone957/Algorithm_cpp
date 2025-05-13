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
int input[501][501];
int dp[501][501];
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int count;
	cin >>count;
	for (int i = 0; i < count; i++)
	{
		for (int j = 0; j < i + 1; j++)
		{
			int num;
			cin >> num;
			input[i][j] = num;
		}
	}
	dp[0][0] = input[0][0];
	for (int i = 1; i < count; i++)
	{
		for (int j = 0; j < i + 1; j++)
		{
			if (j == 0)//삼각형에서 시작점일때는 바로 위에껏만
			{
				dp[i][j] = input[i][j] + dp[i - 1][j];
			}
			else if (j == i)// 삼각형에서 맨 마지막 점일때도 이하 동일
			{
				dp[i][j] = input[i][j] + dp[i - 1][j - 1];
			}
			else// 이제 중간에 있는거는 위에 잇는것들 중에서 dp 계산한것 중에서 큰것만 더해서 dp테이블 재정의
			{
				dp[i][j] = max(dp[i - 1][j - 1], dp[i-1][j]) + input[i][j];
			}
		}
	}
	//int result= max_element(dp[count], dp[count]+count+1);
	cout << *max_element(dp[count-1], dp[count-1]+count);
}