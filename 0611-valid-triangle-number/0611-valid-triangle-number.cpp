class Solution {
public:
    int triangleNumber(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int answer{};

        for(int i = 0; i < nums.size(); ++i)
        {
            for(int j = i + 1; j < nums.size(); ++j)
            {
                for(int k = nums.size() - 1; k > j; --k)
                {
                    if(nums[i] + nums[j] > nums[k])
                    {
                        answer += k - j;
                        break;
                    }
                }
            }
        }
        
        return answer;
    }

};