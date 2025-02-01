#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <sstream>
#include <queue>

using namespace std;
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int pNum,rNum;
	cin >> pNum>> rNum;
	queue<int> qArr;
	for (int i = 1; i <= pNum; i++)
	{
		qArr.push(i);
	}
	vector<int> resultArr;
	int count=1;
	while (!qArr.empty())
	{
		if (count == rNum)
		{
			resultArr.push_back(qArr.front());
			qArr.pop();
			count = 0;
		}
		else
		{
			qArr.push(qArr.front());
			qArr.pop();
		}
		count++;
	}
	cout << "<";
	for (int i = 0; i < resultArr.size(); i++)
	{
		cout << resultArr[i];
		if (i < resultArr.size() - 1)
			cout << ", ";
	}
	cout << ">";

}