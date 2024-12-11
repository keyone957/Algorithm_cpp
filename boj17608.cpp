#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <sstream>
#include <stack>
using namespace std;
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int count;
	cin >> count;
	stack<int> arr;
	for (int i = 0; i < count; i++)
	{
		int temp;
		cin >> temp;
		arr.push(temp);
	}
	int answer = 0;
	int max = 0;
	while (arr.size())
	{
		if (max < arr.top())
		{
			max = arr.top();
			answer++;
		}
		arr.pop();

	}
	cout << answer;
}