class Solution {
public:
    int arrayPairSum(vector<int>& nums) {
        int big = *max_element(nums.begin(), nums.end());
        int small = *min_element(nums.begin(), nums.end());

        vector<int> result = CountingSort(nums, big, small);

        int sum{};
        for(int i = 0; i < result.size(); i += 2)
        {
            sum += result[i];
        }

        return sum;
    }

private:
    vector<int> CountingSort(const vector<int>& nums, int big, int small)
    {
        vector<int> countArray;
        if(small < 0)
        {
            countArray.resize(big - small + 1);

            for(const auto& num : nums)
            {
                ++countArray[num - small];
            }
            for(int i = 1; i < countArray.size(); ++i)
            {
                countArray[i] += countArray[i - 1];
            }

            vector<int> output(nums.size(), 0);
            for(int i = nums.size() - 1; i >= 0; --i)
            {
                int value = nums[i] - small;
                int index = --countArray[value];

                output[index] = value + small;
            }
            return output;
        }
        else
        {
            countArray.resize(big + 1);

            for(const auto& num : nums)
            {
                ++countArray[num];
            }
            for(int i = 1; i < countArray.size(); ++i)
            {
                countArray[i] += countArray[i - 1];
            }

            vector<int> output(nums.size(), 0);
            for(int i = nums.size() - 1; i >= 0; --i)
            {
                int value = nums[i];
                int index = --countArray[value];

                output[index] = value;
            }
            return output;
        }
    }
};