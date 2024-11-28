#include <iostream>
#include <vector>
using namespace std;
int main()
{
	string num;
	cin >> num;

	int c1 = 0;
	int c0 = 0;
	for (int i = 0; i < num.length(); i++)
	{
		if (num[i] != num[i + 1])
		{
			if (num[i] == '1')
				c1++;
			else if (num[i] == '0')
				c0++;
		}

	}
	int min;
	if (c1 > c0)
	{
		min = c0;
	}
	else if (c1 < c0)
	{
		min = c1;
	}
	cout << min << endl;
}