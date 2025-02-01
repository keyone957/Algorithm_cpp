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

	vector<string> words;
	for (int i = 0; i < count; i++)
	{
		string word;
		cin >> word;
		words.push_back(word);
	}
	int result = 0;
	for (int i = 0; i < count; i++)
	{
		stack<char> wordStack;
		bool isCorrect = false;
		for (int j = 0; j < words[i].size(); j++)
		{

			if (!wordStack.empty())
			{
				if (wordStack.top() == 'A' && words[i][j] == 'A')
				{
					wordStack.pop();
				}
				else if (wordStack.top() == 'B' && words[i][j] == 'B')
				{
					wordStack.pop();
				}
				else
				{
					wordStack.push(words[i][j]);
				}
			}
			else if (wordStack.empty())
			{
				wordStack.push(words[i][j]);
			}
		}
		if (wordStack.empty())
			isCorrect = true;
		if (isCorrect)
		{
			result++;
		}
	}
	cout << result;
}