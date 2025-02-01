#include <iostream>
#include <vector>
#include <string>
using namespace std;
int main()
{
/*
부분합 문제.
시간초과 관련 
ios::sync_with_stdio(false);
cin.tie(NULL);
cout.tie(NULL);
==> 종종 시간초과가 뜨면 이거 넣으면 해결된다네요
 */

	int N, M;
	int sumList[100000] = {};
	vector<int> answer;

	cin >> N;
	cin >> M;
	for (int i = 1; i <= N; i++)
	{
		int temp;
		cin >> temp;
		sumList[i] = sumList[i - 1] + temp;//==> 합배열 구하는 공식. S[i]=S[i-1]+A[i] s:합배열 a : 일반배열
	}
	
	
	for (int i = 1; i <= M; i++)
	{
		int startIdx, endIdx;
		cin >> startIdx;
		cin >> endIdx;
		int result = 0;
		result = sumList[endIdx] - sumList[startIdx - 1];//i~j까지 구간합 공식. 
		answer.push_back(result);
	}
	for (int i = 0; i < M; i++)
	{
		cout << answer[i] << "\n";//endl보다는 \n이용해서 나타내는게 시간초과가 안뜨더라.
		
	}
	

}