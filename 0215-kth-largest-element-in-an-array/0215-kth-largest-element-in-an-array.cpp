class Solution {
public:
    int Partition(vector<int>& nums, int lo, int hi)
    {
        int pivot = nums[hi];
        int index = lo;
        for(int i = lo; i < hi; ++i)
        {
            if(pivot >= nums[i])
            {
                swap(nums[i], nums[index++]);
            }
        }

        swap(nums[index], nums[hi]);

        return index;
    }

    int FindKthLargestIndex(vector<int>& nums, int kIndex, int lo, int hi)
    {
        int index = Partition(nums, lo, hi);

        if (index == kIndex)
        {
            return nums[index];
        }
        else if (index < kIndex)
        {
            int temp = index;
            while(index + 1 < nums.size() && nums[index + 1] == nums[temp])
            {
                if(index + 1 == kIndex)
                {
                    return nums[index + 1];
                }
                ++index;
            }

            return FindKthLargestIndex(nums, kIndex, index + 1, hi);
        }
        else
        {
            int temp = index;
            while(index - 1 >= 0 && nums[index - 1] == nums[temp])
            {
                if(index - 1 == kIndex)
                {
                    return nums[index - 1];
                }
                --index;
            }

            return FindKthLargestIndex(nums, kIndex, lo, index - 1);
        }

        return -1;
    }

    int findKthLargest(vector<int>& nums, int k) {
        int lo = 0, hi = nums.size() - 1;
        int kIndex = nums.size() - k;
        return FindKthLargestIndex(nums, kIndex, lo, hi);
    }
};