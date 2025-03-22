class Solution {
public:
    int minimumCost(vector<int>& cost) {
        sort(cost.rbegin(), cost.rend());
        int sum{};

        for(int i = 0; i < cost.size(); i += 3)
        {
            if(cost.size() <= i + 1)
            {
                sum += cost[i];
                break;
            }
            sum += cost[i] + cost[i + 1];
        }

        return sum;
    }
};