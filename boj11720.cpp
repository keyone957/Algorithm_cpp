#include <iostream>
#include <vector>
#include <string>
using namespace std;
int main()
{
	int count;
	string numbers;
	int sum = 0;
	cin >> count;
	cin >> numbers;
	for (int i = 0; i < numbers.size(); i++)
	{
		int num = numbers[i] - '0';
		sum += num;
	}
	cout << sum;
}