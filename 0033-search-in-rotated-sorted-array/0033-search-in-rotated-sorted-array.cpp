class Solution {
public:
    int search(vector<int>& nums, int target) {
        	int left = 0, right = nums.size() - 1;
	int mid = (left + right) / 2;

	while (left <= right)
	{
		if (nums[mid] < nums[right])
		{
			right = mid;
			mid = (left + right) / 2;
		}
		else if (nums[mid] > nums[right])
		{
			left = mid + 1;
			mid = (left + right) / 2;
		}
		else
		{
			break;
		}
	}

	auto it = std::lower_bound(nums.begin(), nums.begin() + mid, target);
	if (*it == target)
	{
		return it - nums.begin();
	}
	it = std::lower_bound(nums.begin() + mid, nums.end(), target);
	if (it != nums.end() && *it == target)
	{
		return it - nums.begin();
	}

	return -1;
    }
};