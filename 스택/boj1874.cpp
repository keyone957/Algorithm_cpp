#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <string>
#include <stack>
using namespace std;
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int count;
	cin >> count;
	vector<int> initArr(count);//==> 크기만큼 벡터 배열 초기화 해줘야함
	stack<int> arr;
	vector<string> result;
	for (int i = 0; i < count; i++)
	{
		cin >> initArr[i];
	}
	
	int num = 1;
	bool canPrint = true;	
	for (int i = 0; i < count; i++)
	{
		int curNum = initArr[i];
		if (curNum >= num)//현재 비교할 수열의 수가 증가시켜줄 수보다 크면 
		{
			while (curNum>=num)//똑같아 질때 까지 num증가 시키고
			{
				arr.push(num++);
				result.push_back("+");
			}
			arr.pop();//이제 조건 만족하면 pop해줘서 그 수는 없애버리고
			result.push_back("-");
		}
		else//현재 비교할 수열의 값이 증가시켜줄 수보다 작으면
		{
			int curPop=arr.top();//
			arr.pop();
			if (curPop > curNum)//스택의 가장위의 수가 만들어야하는 수열의 수보다 크다면 수열이 출력 불가능 함
			{
				cout << "NO";
				canPrint = false;
				break;
			}
			else
			{
				result.push_back("-");
			}
		}
	}
	if (canPrint)
	{
		for (int i = 0; i < result.size(); i++)
		{
			cout << result[i] << "\n";
		}
	}
}