#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;
int main()
{
	int count;
	double sum=0;
	
	vector<double> num;

	cin >> count;
	for (int i = 0; i < count; i++)
	{
		int temp;
		cin >> temp;
		num.push_back(temp);
	}
	double maxNum = *max_element(num.begin(), num.end());
	/*
	백터에서 최대값 구할때 사용하는 식.
	int min = *min_element(vec.begin(), vec.end());
	이거는 최솟값	
	*/
	for (int i = 0; i < num.size(); i++)
	{
		sum += num[i];
	}
	
	 double answer = sum*100/maxNum/count;
	cout << answer;

}