class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int left = 0;
        int right = 1;
        int arrSize = prices.size();
        int answer = -1;
        while (left < arrSize && right < arrSize)
        {
            int leftV = prices[left];
            int rightV = prices[right];
            if (rightV >= leftV)// 우측값이 왼쪽 값보다 크다면 갱신
            {
                answer = max(answer, rightV - leftV);
                right++;
            }
            else//왼쪽 주식이 오른쪽 주식 보다 작은 값이면 이거는 무조건 손해 이므로 왼쪽 주식의 
            //포인터를 오른쪽 주식부터 시작해서 다시 그 위치부터 시작
            {
                left = right;
                right++;
            }
        }
        if (answer <= -1)
        {
            answer = 0;
        }
        return answer;
    }
};