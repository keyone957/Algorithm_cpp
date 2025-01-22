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
	vector<int> initArr(count);//==> ũ�⸸ŭ ���� �迭 �ʱ�ȭ �������
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
		if (curNum >= num)//���� ���� ������ ���� ���������� ������ ũ�� 
		{
			while (curNum>=num)//�Ȱ��� ���� ���� num���� ��Ű��
			{
				arr.push(num++);
				result.push_back("+");
			}
			arr.pop();//���� ���� �����ϸ� pop���༭ �� ���� ���ֹ�����
			result.push_back("-");
		}
		else//���� ���� ������ ���� ���������� ������ ������
		{
			int curPop=arr.top();//
			arr.pop();
			if (curPop > curNum)//������ �������� ���� �������ϴ� ������ ������ ũ�ٸ� ������ ��� �Ұ��� ��
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