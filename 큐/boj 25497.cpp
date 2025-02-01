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
	string skill;
	char input;
	for (int i = 0; i < count; i++) {
		cin >> input;
		skill += input;
	}
	stack<char> LRSkill;
	stack<char> SKSkill;
	//�׳� ���� LR ���ϰ� SK�� ��ų ������ ��������
	int result = 0;
	for (int i = 0; i < skill.size(); i++)
	{
		if (skill[i] >= 49 && skill[i] <= 57)
		{
			result++;
		}
		if (skill[i] == 'L')
		{
			LRSkill.push(skill[i]);
		}
		else if (skill[i] == 'S')
		{
			SKSkill.push(skill[i]);
		}
		if (skill[i] == 'R')
		{
			if (!LRSkill.empty())
			{
				LRSkill.pop();
				result++;
			}
			else
				break;//���࿡ ���Ϸ� �ߴµ� ����ִٸ� �տ� ������ų�� ���ߴٴ¶��̹Ƿ� �� �ݺ��� BREAK
		}
		if (skill[i] == 'K')
		{
			if (!SKSkill.empty())
			{

				SKSkill.pop();
				result++;
			}
			else
			{
				break;
			}
		}
	}
		cout << result;
}