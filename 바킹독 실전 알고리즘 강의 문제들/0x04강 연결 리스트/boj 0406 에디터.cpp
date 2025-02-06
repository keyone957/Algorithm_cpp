#include <algorithm>
#include <deque>
#include <functional>
#include <iostream>
#include <iterator>
#include <list>
#include <map>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <string>
#include <vector>
using namespace std;
int main()
{
	/*
	L Ŀ�� �������� �̵� /�ǿ����̸� ����
	D Ŀ�� ���������� �̵�/ �� �������̸� ����
	B Ŀ�����ʿ� �ִ� ���� ���� / ����� ���̸� ����
	P X => X��¹��� Ŀ�� ���ʿ� �߰�
	*/
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	string firstArr;
	cin >>firstArr;
	int count;
	cin >> count;
	cin.ignore();// ���� cin�۾����� ���๮�� �����ϱ� ����
	vector<string> editor;
	list<char> listArr;
	for (int i = 0; i < firstArr.size(); i++)
	{
		listArr.push_back(firstArr[i]);
	}

	for (int i = 0; i < count; i++)
	{
		string go;
		getline(cin, go);
		editor.push_back(go);
	}
	list<char>::iterator t = listArr.end();
	for (int i = 0; i < count; i++)
	{
		if (editor[i][0] == 'L')
		{
			if (t != listArr.begin())
			{
				t--;
			}
		}
		else if(editor[i][0]=='D')
		{ 
			if (t != listArr.end())
			{
				t++;
			}
		}
		else if (editor[i][0] == 'B')
		{
			if (t != listArr.begin())
			{
				/*
				���� ������ listArr.erase(t)�� �߾��µ�
				���࿡ �̰͸� ������ �����Ŀ� �� �����ִ� ������ �����ϱ� ������ ��ȿȭ�� iterator�� ����ϱ� ������ 
				������ ����
				*/
				t--;// ���� iterator�� �������� �̵��Ŀ�
				t=listArr.erase(t);//erase �� ��ȯ�Ǵ� ���ο� iterator�� �����ؼ� �� ���� ������ ��ȿ�ϰ� ����
			}
		}
		else if (editor[i][0] == 'P')
		{
			listArr.insert(t,editor[i][2]);
		}
	}
	
	for (auto i :listArr) cout << i;
}