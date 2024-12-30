class Solution {
public:
    bool increasingTriplet(vector<int>& nums) {
        int first = INT_MAX, second = INT_MAX;

        for(int i = 0; i < nums.size(); ++i)
        {
            cout << first << ' ' << second << endl;
            
            if(first > nums[i])
            {
                first = nums[i];
            }
            else
            {
                if(second > nums[i] && first != nums[i])
                {
                    second = nums[i];
                }
            }

            if(first < second && second < nums[i])
            {
                return true;
            }
        }
        
        return false;
    }
};