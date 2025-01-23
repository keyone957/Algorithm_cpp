#include <iostream>
#include <vector>
#include <string>
#include <sstream>

using namespace std;
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int sum=1;
	for (int i = 0; i < 3; i++)
	{
		int num;
		cin >> num;
		sum *= num;
	}
	
	stringstream convertNum;
	convertNum << sum;
	string result;
	convertNum >> result;

	vector<int> arr(10,0);
	for (int i = 0; i < result.size(); i++)
	{
		arr[result[i] - 48]++;
	}
	for (int i = 0; i < arr.size(); i++)
	{
		cout << arr[i] << "\n";
	}
}