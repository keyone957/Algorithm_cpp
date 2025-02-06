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
	L 커서 왼쪽으로 이동 /맨왼쪽이면 무시
	D 커서 오른쪽으로 이동/ 맨 오른쪽이면 무시
	B 커서왼쪽에 있는 문자 삭제 / 문장맨 앞이면 무시
	P X => X라는문자 커서 왼쪽에 추가
	*/
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	string firstArr;
	cin >>firstArr;
	int count;
	cin >> count;
	cin.ignore();// 이전 cin작업후의 개행문자 제거하기 위함
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
				내가 원래는 listArr.erase(t)만 했었는데
				만약에 이것만 넣으면 삭제후에 그 남아있는 공간에 접근하기 때문에 무효화된 iterator을 사용하기 때문에 
				오류가 난다
				*/
				t--;// 먼저 iterator을 왼쪽으로 이동후에
				t=listArr.erase(t);//erase 후 반환되는 새로운 iterator를 저장해서 그 다음 동작을 유효하게 만듦
			}
		}
		else if (editor[i][0] == 'P')
		{
			listArr.insert(t,editor[i][2]);
		}
	}
	
	for (auto i :listArr) cout << i;
}