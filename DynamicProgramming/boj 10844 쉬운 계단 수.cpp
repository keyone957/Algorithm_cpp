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
long dp[101][11];
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int count;
	cin >> count;
	dp[1][0] = 0;
	//dp[i][n] ==> i -> ��ܰ��� n���� ������ ��ܼ��϶� ����� ����
	for (int i = 1; i <= 9; i++)
	{
		dp[1][i] = 1;//�ϴ� ��� 1�϶� �� 1����
	}
	for (int i = 2; i <= count; i++) {
		// ���ڸ��� 0�� ���==> �ٷ� ���ڸ��� 1�� ����
		dp[i][0] = dp[i - 1][1];
		// ���ڸ��� 1~8�� ���--> ���ڸ��� d-1 �Ǵ� d+1
		for (int j = 1; j <= 8; j++) {
			dp[i][j] = (dp[i - 1][j - 1] + dp[i - 1][j + 1]) % 1000000000;
		}
		// ���ڸ��� 9�� ���--> �ٷ� ���ڸ��� 8�� ����
		dp[i][9] = dp[i - 1][8];
	}
	long ans = 0;
	for (int i = 0; i <= 9; i++) {
		ans += dp[count][i];
	}
	cout << ans % 1000000000 << "\n";
	return 0;

}