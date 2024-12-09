class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<vector<string>> table(n + 1);
        table[0] = {""};

        for(int i = 1; i <= n; ++i)
        {
            for(int j = 0; j < i; ++j)
            {
                int k = i - 1 - j;
                for(const string& inside : table[j])
                {
                    for(const string& outside : table[k])
                    {
                        table[i].push_back("(" + inside + ")" + outside);
                    }
                }
            }
        }

        return table[n];
    }
};