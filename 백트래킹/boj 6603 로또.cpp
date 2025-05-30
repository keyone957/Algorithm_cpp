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
int n = -1;
vector<int> arr;
vector<bool> isUsed;
vector<int> inputArr;
void func(int k)
{
	if (k == 6)
	{
		for (int i = 0; i < 6; i++)
		{
			cout << arr[i] << ' ';// ���� ������ �ϼ��Ѱ� �̹Ƿ� ���
		}
		cout << '\n';
		return;
	}
	for (int i = 0; i < n; i++)
	{
		if (!isUsed[i]&&k==0 || inputArr[i] > arr[k - 1])//������������ ���
		{
			arr[k] = inputArr[i];//���� ���� �ִ� ���� i�� ����
			isUsed[i] = true;//�� ���� ���� ���̹Ƿ� true�� ��������
			func(k + 1);//���� ������ �� ���� ���Ϸ� �Ѵܰ� �� ������.
			isUsed[i] = false;//���� a ��° ���� ���� ��� ��쿡 ���� �� Ȯ�� ������ 
			//i�� ������� ���� ���·� �����������
		}
	}
}
void reset()
{
	arr.clear();
	isUsed.clear();
	inputArr.clear();
	cout << "\n";
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	while (n != 0)
	{
		cin >> n;
		for (int i = 0; i < n; i++)
		{
			int input;
			cin >> input;
			inputArr.push_back(input);
		}
		arr.resize(n + 1);
		isUsed.resize(n + 1);
		inputArr.resize(n + 1);
		func(0);
		reset();
	}
}