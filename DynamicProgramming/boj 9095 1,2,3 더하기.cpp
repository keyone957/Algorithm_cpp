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
	//�ּ� 3���� �ʱⰪ�� �˰� �־����.
	cin >> count;
	for (int i = 4; i < 11; i++)
	{
		dp[i] = dp[i - 1] + dp[i - 2] + dp[i - 3];
		//��ȭ��
		//ex 
		/*dp[4]�� ���ø� ����
		* 1 1 1 1 , 3 1 , 2 1 1, 1 2 1 --> 3�� 1 2 3 �� ������ ��Ÿ���� ����� 1�� �߰� ���� ==>d[3]
		* 1 1 2, 2 2 --> 2�� 1 2 3�� ������ ��Ÿ���� ����� 2�� �߰� ���� ==>d[2]
		* 1 3 --> 1�� 1 2 3�� ������ ��Ÿ���� ��� ����� 3�� �߰� ���� ==>d[1]
		--> ���� ���� 1,2,3���� �����°� ������ �з��� �غô�.
		d[4]�� d[1]+d[2]+d[3]
		���� ��ȭ���� ������ ����
		*/ 
	}
	for (int i = 0; i < count; i++)
	{
		int n;
		cin >>n;
		cout << dp[n] << "\n";
	}
}