#include <iostream>
#include <vector>
#include <string>
using namespace std;
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int N,M;
	int sumList[1025][1025] = {};
	vector<int> answer;
	cin >> N>>M;
	for (int i = 1; i <= N; i++)
	{
		for (int j = 1; j <= N; j++)
		{
			int temp;
			cin >> temp;
			sumList[i][j] = sumList[i][j - 1] + sumList[i - 1][j] - sumList[i - 1][j - 1] + temp;//2차원 배열 구간합 공식

		}
	}

	for (int i = 0; i < M; i++)
	{
		int x1, y1, x2, y2;
		cin >> x1 >> y1 >> x2 >> y2;
		int result=0;
		result = sumList[x2][y2] - sumList[x1 - 1][y2] - sumList[x2][y1 - 1] + sumList[x1 - 1][y1 - 1];//답구할때 구간합배열 구할때랑 비슷함
		answer.push_back(result);
	}
	for (int i = 0; i < M; i++)
	{
		cout << answer[i] << "\n";
	}
	
}    