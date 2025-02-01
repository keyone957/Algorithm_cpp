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
	vector<string> input(count);
	for (int i = 0; i < count; i++)
	{
		cin >> input[i];
	}

	for (int i = 0; i < count; i++)
	{
		stack<char> vps;
		bool isNo = false;
		for (int j = 0; j < input[i].size(); j++)
		{
			/*cout << input[i][j]<<endl;*/
			if (input[i][j] == '(')
			{
				vps.push(input[i][j]);
			}
			else if (!vps.empty()&&input[i][j] == ')')
			{
				vps.pop();
			}
			else
			{
				isNo = true;
				break;
			}
		}

		if (isNo||!vps.empty())
		{
			cout << "NO" << "\n";
		}
		else
			cout << "YES" << "\n";
	}

}