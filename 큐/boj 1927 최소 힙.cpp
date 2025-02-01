#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <sstream>
#include <queue>
#include <functional>
using namespace std;
int main()
{
	//우선순위 큐 문제
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	priority_queue<int, vector<int>, greater<int>> qArr;
	//가장 작은 값이 top에 있음
	int count;
	cin >> count;
	vector<int> resultArr;
	for (int i = 0; i < count; i++)
	{
		int input;
		cin >> input;
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
		cout << resultArr[i]<<"\n";
	}
}