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
int input;
string line;
void Func(int a)
{
	
	if (a != 0)
	{
		line += "____";
	}
	if (input == a)
	{
		cout << line << "\"����Լ��� ������?\"" << "\n";
		cout << line << "\"����Լ��� �ڱ� �ڽ��� ȣ���ϴ� �Լ����\"" << "\n";
		cout << line << "��� �亯�Ͽ���." << "\n";
		for (int i = 0; i < input; i++)
		{
			line.erase(0, 4);
			cout << line << "��� �亯�Ͽ���." << "\n";
		}
	}
	else
	{
		cout << line << "\"����Լ��� ������?\"" << "\n";
		cout << line << "\"�� ����. �������� �� �� ����⿡ �̼��� ��� ������ ����� ������ �־���." << "\n";
		cout << line << "���� ������� ��� �� ���ο��� ������ ������ �߰�, ��� �����Ӱ� ����� �־���." << "\n";
		cout << line << "���� ���� ��κ� �ǾҴٰ� �ϳ�. �׷��� ��� ��, �� ���ο��� �� ���� ã�ƿͼ� ������.\"" << "\n";
		Func(a + 1);
	}

}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> input;
	cout << "��� �� ��ǻ�Ͱ��а� �л��� ������ �������� ã�ư� ������."<<"\n";
	Func(0);
	

}
