class Solution {
public:
    int minimumOperations(vector<int>& nums) {
        unordered_set<int> s;

        for(int i = 0; i < nums.size(); ++i)
        {
            if(nums[i] != 0)
            {
                s.emplace(nums[i]);
            }
        }

        return s.size();
    }
};