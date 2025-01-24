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
	//그냥 차라리 LR 용하고 SK용 스킬 스택을 선언하자
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
				break;//만약에 비교하려 했는데 비어있다면 앞에 사전스킬을 안했다는뜻이므로 걍 반복문 BREAK
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