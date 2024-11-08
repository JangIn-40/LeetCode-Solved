class Solution {
public:
    int rob(vector<int>& nums) {
        	int n = nums.size();
	if (n == 1)
	{
		return nums[0];
	}
	if (n == 2)
	{
		return std::max(nums[0], nums[1]);
	}

	auto robLine = [](std::vector<int>& nums, int start, int end) 
	{
		int prev1 = 0, prev2 = 0;
		for (int i = start; i <= end; ++i) 
		{
			int temp = std::max(prev1, prev2 + nums[i]);
			prev2 = prev1;
			prev1 = temp;
		}
		return prev1;
	};

	int robFirst = robLine(nums, 0, n - 2);
	int robLast = robLine(nums, 1, n - 1);

	return std::max(robFirst, robLast);
    }
};