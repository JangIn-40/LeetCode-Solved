class Solution {
public:
    int integerReplacement(int n) {
        int answer{};

        unsigned int num = n;
        while(num > 1)
        {
            if(num % 2 == 0)
            {
                num /= 2;
            }
            else
            {
                if((num - 1) / 2 == 1)
                {
                    --num;
                }
                else if((num + 1) / 2 % 2 == 0)
                {
                    ++num;
                }
                else
                {
                    --num;
                }
            }
            
            ++answer;
        }

        return answer;
    }
};