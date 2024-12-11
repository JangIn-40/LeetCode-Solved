class Solution {
public:
    bool canJump(vector<int>& nums) {
        int reach{ 0 };

        for(int i = 0; i < nums.size(); ++i)
        {
            if(reach < i)
            {
                return false;
            }
            
            if(reach < i + nums[i])
            {
                reach = i + nums[i];
            }


        }
        
        return true;
    }
};