class Solution {
public:
    int jump(vector<int>& nums) {
        int answer{};
        int maxReach{}, reach{};

        for(int i = 0; i < nums.size() - 1; ++i)
        {
            if(reach >= nums.size() - 1)
            {
                break;
            }

            maxReach = max(maxReach, nums[i] + i);
            if(i == reach)
            {
                reach = maxReach;
                ++answer;
            }
        }

        return answer;
    }
};