class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        string answer;
        for(int i = 0; i < strs[0].size(); ++i)
        {
            char ch = strs[0][i];
            for(int j = 1; j < strs.size(); ++j)
            {
                if(ch != strs[j][i])
                {
                    return answer;
                }
            }
            answer += ch;
        }

        return answer;
    }
};