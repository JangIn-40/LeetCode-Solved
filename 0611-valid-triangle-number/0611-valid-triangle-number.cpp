class Solution {
public:
    int triangleNumber(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int answer{};

        for(int i = 0; i < nums.size(); ++i)
        {
            if(nums[i] == 0)
            {
                continue;
            }
            
            int k = i + 2;
            for(int j = i + 1; j < nums.size(); ++j)
            {
                while(k < nums.size() && nums[i] + nums[j] > nums[k])
                {
                    ++k;
                }

                answer += k - j - 1;
            }
        }
        
        return answer;
    }
};