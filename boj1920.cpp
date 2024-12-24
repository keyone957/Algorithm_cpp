#include<iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;
int main()
{
	/*ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int count;
	vector<int> arr1;

	cin >> count;
	for (int i = 0; i < count; i++)
	{
		int temp;
		cin >> temp;
		arr1.push_back(temp);
	}
	int count2;
	vector<int> arr2;
	vector<int> answer;
	cin >> count2;
	for (int i = 0; i < count2; i++)
	{
		int temp;
		cin >> temp;
		arr2.push_back(temp);
	}

	sort(arr1.begin(), arr1.end());

	for (int i = 0; i < arr2.size(); i++)
	{
		for (int j = 0; j < arr1.size(); j++)
		{
			if (arr2[i] == arr1[j])
			{
				answer.push_back(1);
				break;
			}
			else if (j == arr1.size() - 1)
			{
				answer.push_back(0);
				break;
			}
		}

	}
	for (int i = 0; i < answer.size(); i++)
	{
		cout << answer[i] << "\n";
	}
	==> 시간복잡도 o(n*m) 배열 전체 순환 따라서 시간초과
	*/


}