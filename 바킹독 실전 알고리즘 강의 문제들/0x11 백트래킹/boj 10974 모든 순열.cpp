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
int N, M;
int arr[10];
int isUsed[10];

void func(int a)//���� a������ ���� ����
{
	if (a == N)//M�� ������ ���� ��������
	{
		for (int i = 0; i < N; i++)
		{
			cout << arr[i] << ' ';// ���� ������ �ϼ��Ѱ� �̹Ƿ� ���
		}
		cout << '\n';
		return;
	}
	for (int i = 1; i <= N; i++)
	{
		if (!isUsed[i])
		{
			arr[a] = i;
			isUsed[i] = 1;
			func(a + 1);
			isUsed[i] = 0;
		}
	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> N;
	func(0);
}