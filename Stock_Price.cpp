#include <iostream>
#include <vector>
#include <queue>
using namespace std;



vector<int> solution(vector<int> prices) {
	vector<int> answer;
	queue<int> arr;
	for (int i = 0; i < prices.size(); i++)
	{
		arr.push(prices[i]);
	}
	
	while (!arr.empty())
	{
		for (int i = 0; i < prices.size(); i++)
		{
			int cur = arr.front();//현재 비교할 수를 꺼냄
			arr.pop();//그리고 비교 다 끝났으면 맨 위에 있는 값 빼버리기
			int time = 0;//몇분동안 가격 안떨어지는지 확인하는 time
			if (i + 1 < prices.size())//다음 수에서 끝까지 비교
			{
				for (int j = i + 1; j < prices.size(); j++)
				{
					time++;
					if (cur > prices[j]) break;// 이제 가격 내려 갔으면 break해서 끝
				}
			}
			answer.push_back(time);
		}
	}
	return answer;
}