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
int dp[11];
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int count;
	dp[1] = 1;
	dp[2] = 2;
	dp[3] = 4;
	//최소 3개의 초기값은 알고 있어야함.
	cin >> count;
	for (int i = 4; i < 11; i++)
	{
		dp[i] = dp[i - 1] + dp[i - 2] + dp[i - 3];
		//점화식
		//ex 
		/*dp[4]로 예시를 들어보자
		* 1 1 1 1 , 3 1 , 2 1 1, 1 2 1 --> 3을 1 2 3 의 합으로 나타내는 방법에 1을 추가 따라서 ==>d[3]
		* 1 1 2, 2 2 --> 2를 1 2 3의 합으로 나타내는 방법에 2를 추가 따라서 ==>d[2]
		* 1 3 --> 1을 1 2 3의 합으로 나타내는 방법 방법에 3을 추가 따라서 ==>d[1]
		--> 각각 끝이 1,2,3으로 끝나는걸 나눠서 분류를 해봤다.
		d[4]는 d[1]+d[2]+d[3]
		따라서 점화식은 저렇게 나옴
		*/ 
	}
	for (int i = 0; i < count; i++)
	{
		int n;
		cin >>n;
		cout << dp[n] << "\n";
	}
}