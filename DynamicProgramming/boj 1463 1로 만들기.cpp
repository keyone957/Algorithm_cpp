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
int dp[1000000];
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	dp[1] = 0;
	int n;
	cin >> n;
	for (int i = 2; i <= n; i++)
	{
		dp[i] = dp[i - 1] + 1;// +1을 해주는이유? --> 이게 계쏙 최소의 경우의 수를 구하는것이 아니라 
		//차피 /2 또는/3을 해주면 이전에 계산했던거에서 -1해주는 계산만 경우의수에 +1을 하면 된다. 
		//점화식을 만든것임.
		//예시로
		/*
		2 3 4 5 6 7 8 9 10
		1 1 2 3 2 3 3 2 3 
		-->9를 예시로 들자. 3으로 나눠지니 9를 3으로 나누면 3이죠? 근데 3의 최소 경우의 수는 1이라고 해놨네?
		따라서 이제 나누기 3해준것만 +1을 해주면 된다 이말이야
		*/
		if (i % 3 == 0)
		{
			dp[i] = min(dp[i], dp[i / 3] + 1);
		}
		if (i % 2 == 0)
		{
			dp[i] = min(dp[i], dp[i / 2] + 1);
		}
	}
	cout << dp[n];
}