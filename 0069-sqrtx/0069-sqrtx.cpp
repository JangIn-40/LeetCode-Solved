class Solution {
public:
    int mySqrt(int x) {
        int answer{};

        for(int i = 1; i <= x; ++i)
        {
            long long num = (long long)i * i;
            if(num <= x)
            {
                answer = i;
            }
            else
            {
                return answer;
            }
        }

        return answer;
    }
};