#include <string>
#include <vector>

using namespace std;
vector<int> dp;//i원을 만드는 경우의 수
int solution(int n, vector<int> money) {
    int answer = 0;
    //n 원을 배열에 있는 동전을 가지고 거스름돈이 나올 수 있는 경우의 수
    //
    int arrSize = money.size();
    dp.resize(n + 1);
    dp[0] = 1;//0원을 만드는 경우의 수 1
    for (int i = 0; i < arrSize; i++)
    {
        int coin = money[i];//현재 이 코인을 가지고 만들 수 있는 경우의 수
        for (int j = coin; j <= n; j++)
        {
            dp[j] = dp[j] + dp[j - coin];
            //현재까지 계산된 j원을 만드는 방법의 수
            // + 현재 동전을 하나 더 사용 했을때 j원이 되는 모든 경우의 수 
            // (==>“coin 하나를 추가하기 직전의 상태”의 경우의 수)
        }

    }


    answer = dp[n] % 1000000007;

    return answer;
}