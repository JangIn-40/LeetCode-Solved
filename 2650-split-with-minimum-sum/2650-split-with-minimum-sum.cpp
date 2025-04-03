class Solution {
public:
    int splitNum(int num) {
        vector<int> nums(10, 0);

        while(num)
        {
            nums[num % 10]++;
            num /= 10;
        }

        int num1{}, num2{};
        bool flag{};
        for(int i = 0; i < nums.size(); ++i)
        {
            while(nums[i] != 0)
            {
                if(flag)
                {
                    num1 = num1 * 10 + i;
                    flag = false;
                }
                else
                {
                    num2 = num2 * 10 + i;
                    flag = true;
                }
                nums[i]--;
            }
        }

        return num1 + num2;
    }
};