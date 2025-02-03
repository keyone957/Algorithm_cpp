#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <sstream>
#include <queue>
#include <functional>
struct compare
{
	bool operator()(int a, int b)
	{
		int absA = abs(a);
		int absB = abs(b);
		if (absA == absB)
		{
			return a > b;
		}//2.���࿡ �ΰ��� ������ ���ٸ� ���� �켱���� ���ĵǰ� ��
		return absA > absB;//1.�켱 ���� �������� ���� �ǵ��� �ϵ�
	}
};//==> �ٽ� 
// �켱���� ť�� ����Ͽ� ����� ���� ���� ����ü�� �������.
//
using namespace std;
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	//priority_queue<int> qArr;  // ==  priority_queue<int, vector<int>, less<int>> pq;
	//���� ū���� top�� ����
	//priority_queue<int,vector<int>,greater<int>> qArr
	//���� ���� ���� top�� ����
	priority_queue<int, vector<int>, compare> qArr;
	vector<int>resultArr;
	int count;
	cin >> count;	
	for (int i = 0; i < count; i++)
	{
		int input;
		cin >>input;
		if (input == 0)
		{
			if (qArr.empty())
			{
				resultArr.push_back(0);
			}
			else
			{
				resultArr.push_back(qArr.top());
				qArr.pop();
			}
		}
		else
		{
			qArr.push(input);
		}
	}
	for (int i = 0; i < resultArr.size(); i++)
	{
		cout << resultArr[i] << "\n";
	}
}