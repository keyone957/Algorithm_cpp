#include<iostream>
#include <string>
#include <vector>

using namespace std;
int main()
{
	int a;
	int cnt=1;
	cin >> a;
	while (a != 1)
	{
		if (a % 2 == 1)
		{
			a=3 * a + 1;
		}
		else
		{
			a = a / 2;
		}
		cnt++;

	}
	cout << cnt;
}