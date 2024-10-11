#include <iostream>
#include <vector>
using namespace std;
vector<int> solution(int n, vector<string> words) {
	vector<int> answer;
	//이전에 나왔는지?
	//끝말잇기 조건이 맞는지?
	//현재 몇번째 사람인지?
	//현재 몇번째 루프를 돌앗는지?
	for (int i = 0; i < words.size() - 1; i++)
	{
		if (words[i].back() != words[i + 1].front())//단어 뒤 그 다음단어 한글자가 조건이 맞는지?
		{
			int person = (i + 2) % n == 0 ? n : (i + 2) % n; // 현재 몇 번째 사람인지 계산
			int round = (i + 2 + n - 1) / n; // 현재 몇 번째 차례인지 계산
			return { person, round }; // 조건에 맞지 않으면 반환
		}
		for (int j = 0; j <= i; j++)//이전에 있는 단어들 중 겹치는거 있는지 확인 
		{
			if (words[i + 1] == words[j])
			{
				int person = (i + 2) % n == 0 ? n : (i + 2) % n;
				int round = (i + 2 + n - 1) / n;
				return { person, round };
			}
		}

	}
	answer.push_back(0);
	answer.push_back(0);
	//끝까지 유지가 됐을때

	return answer;
}