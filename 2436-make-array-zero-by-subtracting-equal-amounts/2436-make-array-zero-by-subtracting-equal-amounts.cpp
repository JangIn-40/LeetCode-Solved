class Solution {
public:
    int minimumOperations(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int sum{}, count{};

        for(int i = 0; i < nums.size(); ++i)
        {
            if(nums[i] == 0 || i - 1 >= 0 && nums[i] == nums[i - 1])
            {
                continue; 
            }

            sum += nums[i] - sum;
            ++count;

            if(sum == nums.back())
            {
                break;
            }
        }

        return count;
    }
};