#include <string>
#include <vector>
#include <iostream>
#include<cmath>
using namespace std;
int solution(int number, int limit, int power) {
	int answer = 0;
	vector<int> attackArr;
	for (int i = 1; i <= number; i++)
	{
		int count = 0;
		/////////////////////////////
		//==>����� ¦�� ������ �����Ƿ� �ݺ����� �ݸ� ������ ����� ã�µ����� ������ x 
		//���� ��Ʈi�� ����ϴ°� ����
		for (int j = 1; j <= sqrt(i); j++)
		{
			if (i%j == 0)
			{
				count++;
				if (j != i / j) {
					count++;
				}
			}
		}
		////////////////////////
		attackArr.push_back(count);
	}

	

	for (int i = 0; i < attackArr.size(); i++)
	{
		if (attackArr[i] > limit)
		{
			attackArr[i] = power;
		}
		answer += attackArr[i];

	}
	return answer;
}