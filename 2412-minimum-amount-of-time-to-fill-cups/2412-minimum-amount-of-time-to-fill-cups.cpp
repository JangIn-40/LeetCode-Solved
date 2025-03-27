class Solution {
public:
    int fillCups(vector<int>& amount) {
        int small = 101, big = -1;
        sort(amount.begin(), amount.end());
        
        if(amount[0] + amount[1] <= amount[2])
        {
            return amount[2];
        }
        else
        {
            return (amount[0] + amount[1] + amount[2] + 1) / 2;
        }
    }
};