class Solution {
public:
    int longestPalindrome(string s) 
    {
        vector<int> upper(26, 0);
        vector<int> lower(26, 0);

        for(char& ch : s)
        {
            if(isupper(ch))
            {
                ++upper[ch % 65];
            }
            else
            {
                ++lower[ch % 97];
            }
        }

        int sum{};
        int odd{};
        for(int i = 0; i < upper.size(); ++i)
        {
            if(upper[i] % 2 != 0)
            {
                if(odd < upper[i])
                {
                    sum += max(0, odd - 1);
                    odd = upper[i];
                }
                else
                {
                    sum += max(0, upper[i] - 1);
                }
            }
            else
            {
                sum += upper[i];
            }

            if(lower[i] % 2 != 0)
            {
                if(odd < lower[i])
                {
                    sum += max(0, odd - 1);
                    odd = lower[i];
                }
                else
                {
                    sum += max(0, lower[i] - 1);
                }
            }
            else
            {
                sum += lower[i];
            }
        }

        return sum + odd;
    }
};