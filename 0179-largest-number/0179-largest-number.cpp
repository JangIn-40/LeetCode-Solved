class Solution {
public:
    string largestNumber(vector<int>& nums) {
        
        string largeNum;

        sort(nums.begin(), nums.end(), [&](int a, int b){
            string sa = to_string(a);
            string sb = to_string(b);

            return sa + sb > sb + sa;
        });

        for(int& num : nums)
        {
            string temp = to_string(num);
            largeNum += temp;
        }

        if(largeNum.front() == '0' && largeNum.back() == '0')
        {
            largeNum = "0";
        }

        return largeNum;
    }
};