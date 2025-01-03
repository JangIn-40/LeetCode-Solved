class Solution {
public:
    void wiggleSort(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<int> temp = nums;
        int i = (nums.size() - 1) / 2, j = nums.size() - 1;

        for(int k = 0; k < nums.size(); ++k)
        {
            if(k % 2 == 0)
            {
                nums[k] = temp[i--];
            }
            else
            {
                nums[k] = temp[j--];
            }
        }
    }
};