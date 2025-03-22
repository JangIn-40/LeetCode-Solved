class Solution {
public:
    int minimumCost(vector<int>& cost) {
        sort(cost.begin(), cost.end());
        int sum{};

        for(int i = cost.size() - 1; i >= 0; i -= 3)
        {
            sum += cost[i];
            if(i - 1 >= 0)
            {
                sum += cost[i - 1];
            }
        }

        return sum;
    }
};