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
	//while (input.find(checkWord) != string::npos)
	//{
	//	//cout << input.find(checkWord) << "ã��";
	//	int index = input.find(checkWord);
	//	input = input.erase(index, wordSize);
	//	count++;
	//}
	/*
		���� ���� input�� ���� �ϸ� �ȵǴ°� ���ܰ� �ִ�.
		aabb
		ab
		�̷��� ��ó���� ab�� ������ �ϸ�
		ab�� �� ���ƹ���
		�׷��� ���� 2�� ���͹����µ� �̰� ������
		���� ���� ���ڿ��� �ǵ帮������ index�� �Űܺ�������
	*/

	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	string input;
	getline(cin, input);
	string checkWord;
	getline(cin, checkWord);
	int count = 0;
	int wordSize = checkWord.size();
	size_t pos = 0;
	string temp = input;
	while (true) 
	{
		pos = temp.find(checkWord);
		if (pos == string::npos) break;
		count++;
		// ã�� ��ġ �������� ���ο� �κ� ���ڿ� ����
		temp = temp.substr(pos + wordSize);
	}
	cout << count;

}