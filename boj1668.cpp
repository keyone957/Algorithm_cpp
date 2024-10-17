//#include <iostream>
//#include <vector>
//using namespace std;
//int main()
//{
//	int count, price;
//	vector<int> arr;
//	cin >> count;
//	for (int i = 0; i < count; i++)
//	{
//		cin >> price;
//		arr.push_back(price);
//	}
//	int left = 1;
//	int right = 1;
//
//	int tempLeft = arr[0];
//	int tempRight = arr[count - 1];
//	for (int i = 1; i < count; i++)
//	{
//		if (tempLeft < arr[i])
//		{
//			tempLeft = arr[i];
//			left++;
//		}
//		if (tempRight < arr[count - 1 - i])
//		{
//			tempRight = arr[count - 1 - i];
//			right++;
//		}
//	}
//	cout << left << "\n" << right << "\n";
//
//
//}