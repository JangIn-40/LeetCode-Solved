class Solution {
public:
    int longestConsecutive(vector<int>& nums) {

        if(nums.empty())
        {
            return 0;
        }

        std::sort(nums.begin(), nums.end());
        int answer = 0;
        int sequence = nums[0];
        int max{ 1 };

        for (int i = 1; i < nums.size(); ++i)
        {
            if (nums[i] == sequence)
            {
                continue;
            }
		else if (std::abs(nums[i] - sequence) == 1)
            {
                sequence = nums[i];
                ++max;
            }
            else
            {
                answer = max > answer ? max : answer;
                max = 1;
                sequence = nums[i];
            }
        }

        answer = max > answer ? max : answer;
	    return answer;
    }
};