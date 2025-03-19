class Solution {
public:
    int minimumMoves(string s) {
        bool lastWordIsX = false;
        int num{};

        for(int i = 0; i < s.size();)
        {
            if(s[i] == 'X')
            {
                ++num;
                i += 3;
            }
            else
            {
                ++i;
            }
        }

        return num;
    }
};