class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int answer{};
        int buy = INT_MAX;

        for(int i = 0; i < prices.size() - 1; ++i)
        {
            if(buy > prices[i])
            {
                buy = prices[i];
            }

            if(prices[i] > prices[i + 1])
            {
                answer += prices[i] - buy;
                buy = prices[i + 1];
            }
        }

        if(buy < prices.back())
        {
            answer += prices.back() - buy;
        }

        return answer;
    }
};