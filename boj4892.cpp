#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <string>
using namespace std;
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int num=-1;
	vector<int> arr;
	while (num!=0)
	{
		
		cin >> num;
		arr.push_back(num);
	}
	for (int i = 0; i < arr.size()-1; i++)
	{
		int n1, n2, n3, n4;
		n1 = arr[i] * 3;
		string info;
		if (n1 % 2 == 0)
		{
			n2=n1/2;
			info = "even";
		}
		else
		{
			n2 = (n1 + 1) / 2;
			info = "odd";
		}
		n3 = 3 * n2;
		n4 = n3 /9;


		cout << (i + 1) << ". " << info << " " << n4 << "\n";

	}
}