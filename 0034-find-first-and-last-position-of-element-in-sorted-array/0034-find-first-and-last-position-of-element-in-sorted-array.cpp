class Solution {
public:
    int FindFirst(const vector<int>& nums, int start, int end, int target)
    {
        if(end >= start)
        {
            int mid = start + (end - start) / 2;
            if((mid == 0 || nums[mid - 1] < target) && nums[mid] == target)
            {
                return mid;
            }
            else if(nums[mid] < target)
            {
                return FindFirst(nums, mid + 1, end, target);
            }
            else
            {
                return FindFirst(nums, start, mid - 1, target);
            }
        }

        return -1;
    }

    int FindLast(const vector<int>& nums, int start, int end, int target)
    {
        if(end >= start)
        {
            int mid = start + (end - start) / 2;
            if((mid == nums.size() - 1 || nums[mid + 1] > target) && nums[mid] == target)
            {
                return mid;
            }
            else if(nums[mid] <= target)
            {
                return FindLast(nums, mid + 1, end, target);
            }
            else
            {
                return FindLast(nums, start, mid - 1, target);
            }
        }

        return -1;
    }

    vector<int> searchRange(vector<int>& nums, int target) {
        int start = 0, end = nums.size() - 1;

        int first = FindFirst(nums, start, end, target);
        if(first == -1)
        {
            return {-1, -1};
        }

        int last = FindLast(nums, start, end, target);

        return {first, last};
    }
};