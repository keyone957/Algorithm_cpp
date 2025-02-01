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
	string input;
	cin >> input;


	stack<char> vps;
	int isAnswer = 0;
	for (int j = 0; j < input.size(); j++)
	{
		if (input[j] == '(')
		{
			vps.push(input[j]);
		}
		else if (input[j] == ')')
		{
			if (!vps.empty())
			{
				vps.pop();
			}
			else
			{
				isAnswer++;
			}
		}
		else
		{
			isAnswer++;
		}
	}

	if (!vps.empty())
	{
		cout << isAnswer + vps.size();
	}
	else
		cout << isAnswer;

}