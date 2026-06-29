/*
k번 다익스트라 사용하면될것 같음 그대신에 이제 횟수를 같이 저장하면서 가야할듯?
*/
class Solution {
    vector<pair<int, int>> adj[101];
    int cost[101][101];
    /*
    i번 노드로 들어왔을때
    j번 방문했다 치면
    그때의 최소비용
    */
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        int answer = 0;
        for (int i = 0; i < flights.size(); i++)
        {
            int start = flights[i][0];
            int end = flights[i][1];
            int cost = flights[i][2];
            adj[start].push_back({ end,cost });
        }
        // int stop=0;
        fill(cost[0], cost[101], 1e9);
        queue<pair<int, int>> q;
        q.push({ src,0 });
        cost[src][0] = 0;
        while (!q.empty())
        {
            pair<int, int> cur = q.front();
            q.pop();
            int curNode = cur.first;
            int stop = cur.second;
            for (int i = 0; i < adj[cur.first].size(); i++)
            {
                int nextNode = adj[curNode][i].first;
                int nextCost = adj[curNode][i].second;
                if (stop <= k && cost[curNode][stop] + nextCost < cost[nextNode][stop + 1])
                    //현재 경유 횟수가 k이하 일때
                    //현재 까지 비용 + 이동 비용 < cost[다음 노드][다음 경유 횟수] 보다 작을때
                    //갱신 가능.
                {
                    cost[nextNode][stop + 1] = cost[curNode][stop] + nextCost;
                    q.push({ nextNode, stop + 1 });
                }
            }

        }
        int min_price = 1e9;
        for (int i = 0; i <= k + 1; i++)
        {
            if (cost[dst][i] < min_price)
            {
                min_price = cost[dst][i];
            }
        }
        //결국 도달이 가능했을때 모든 정류장 이동횟수 중에서 가장 적은 cost의 비용을 반환해야함
        answer = (min_price == 1e9) ? -1 : min_price;
        return answer;
    }
};