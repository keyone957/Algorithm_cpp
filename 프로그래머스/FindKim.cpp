#include <string>
#include <vector>

using namespace std;

string solution(vector<string> seoul) {
	string answer = "";
	int count = 0;
	for (int i = 0; i < seoul.size(); i++)
	{
		if (seoul[i] == "Kim")
		{
			count = i; break;
		}
	}
	answer = "�輭���� " + to_string(count) + "�� �ִ�";
	return answer;
}