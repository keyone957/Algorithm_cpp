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
int dp[10001];
int card[10001];
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	/*
	dp���̺� : ī�� i���� ��µ� ���� �ִ� ���
	��ȭ�� ���� ���
	ī�� i���� �� �� �������� �� īƮ���� �¥���ϱ�?
	ī������ ũ��� 1~i����.
	if ī��j ��¥�� ���� ��ٸ� ������ dp[i-j] ��ŭ�� �ִ� ������� ��� �Ҽ� ����
	ex)
	i�� 3�϶� 
	�������� �� ī���� ũ�� j�� 1 �Ǵ� 2 ����

	j = 1 : dp[2] = dp[2-1] + P1 = dp[1] + 1 = 1 + 1 = 2

	j = 2 : dp[2] = dp[2-2] + P2 = dp[0] + 5 = 0 + 5 = 5

	�ִ밪 ���� �� dp[2] = 5
	
	i�� 4�� ��
	j = 1, 2, 3, 4

	j=1 : dp[4] = dp[3] + P1 = 6 + 1 = 7

	j=2 : dp[4] = dp[2] + P2 = 5 + 5 = 10

	j=3 : dp[4] = dp[1] + P3 = 1 + 6 = 7

	j=4 : dp[4] = dp[0] + P4 = 0 + 7 = 7

	�ִ밪 �� dp[4] = 10
	�̷� ������ �ִ밪 �����ذ��鼭 ���Ѵ�
	*/
	int cardCount;
	cin >> cardCount;
	for (int i = 1; i <= cardCount; i++)
	{
		cin >> card[i];
	}
	card[0] = 0;
	dp[0] = 0;
	for (int i = 1; i <= cardCount; i++)
	{
		for (int j = 1; j <= i; j++)
		{
			dp[i] = max(dp[i], dp[i - j] + card[j]);
		}
	}
	cout << dp[cardCount];
}