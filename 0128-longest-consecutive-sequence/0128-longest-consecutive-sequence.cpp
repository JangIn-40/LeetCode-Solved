class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        std::unordered_map<int, int> umNums;
        int answer{};
        
        for (const auto& num : nums)
        {
            umNums[num] = 0;
        }

        for (const auto& num : nums)
        {
            if (umNums[num] == 0)
            {
                int sequence = num + 1;
                int length{ 1 };
                while (umNums.find(sequence) != umNums.end())
                {
                    if (umNums[sequence] != 0)
                    {
                        length += umNums[sequence];
                        break;
                    }
                    else
                    {
                        ++length;
                        umNums[sequence] = length;
                    }

                    ++sequence;
                }

                umNums[num] = length;
                if (length > answer)
                {
                    answer = length;
                }
            }
        }

        return answer;
    }
};