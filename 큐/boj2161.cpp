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

	int num;
	cin >> num;
	int count = 1;
	queue<int> arr;
	for (int i = 1; i <= num; i++)
	{
		arr.push(i);
	}
	while (arr.size() > 1)
	{
		if (count % 2 != 0)
		{
			cout <<arr.front()<<" ";
			arr.pop();
		}
		else
		{
			int swap = arr.front();
			arr.pop();
			arr.push(swap);
		}
		count++;
	}
	cout << arr.front();

}