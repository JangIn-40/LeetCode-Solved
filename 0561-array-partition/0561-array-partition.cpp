class Solution {
public:
    int arrayPairSum(vector<int>& nums) {
        vector<int> result = RadixSort(nums);

        int sum{};
        for(int i = 0; i < result.size(); i += 2)
        {
            sum += result[i];
        }

        return sum;
    }

private:
    void CountingSort(vector<int>& nums, int exp)
    {
        if(nums.empty())
        {
            return;
        }

        vector<int> count(10, 0);

        for(const auto& num : nums)
        {
            int index = abs(num) / exp % 10;
            ++count[index];
        }
        for(int i = 1; i < count.size(); ++i)
        {
            count[i] += count[i - 1];
        }

        vector<int> output(nums.size());
        for(int i = nums.size() - 1; i >= 0; --i)
        {
            int value = abs(nums[i]) / exp % 10;
            int index = --count[value];

            output[index] = nums[i];
        }

        for(int i = 0; i < nums.size(); ++i)
        {
            nums[i] = output[i];
        }
    }

    vector<int> RadixSort(const vector<int>& nums)
    {
        vector<int> negatives, positives;

        for(const auto& num : nums)
        {
            if(num < 0)
            {
                negatives.push_back(num);
            }
            else
            {
                positives.push_back(num);
            }
        }

        int maxNegative = negatives.empty() ? 0 : abs(*min_element(negatives.begin(), negatives.end()));
        int maxPositive = positives.empty() ? 0 : abs(*max_element(positives.begin(), positives.end()));
        int maxValue = max(maxNegative, maxPositive);

        for(int exp = 1; maxValue / exp > 0; exp *= 10)
        {
            CountingSort(negatives, exp);
            CountingSort(positives, exp);
        }

        reverse(negatives.begin(), negatives.end());
        negatives.insert(negatives.end(), positives.begin(), positives.end());

        return negatives;
    }
};