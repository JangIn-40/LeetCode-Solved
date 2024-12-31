class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        sort(g.begin(), g.end());
        sort(s.begin(), s.end());

        int i{}, j{};
        int answer{};

        while(i < g.size() && j < s.size())
        {
            if(g[i] <= s[j])
            {
                ++answer;
                ++i;
            }
            ++j;
        }

        return answer;
    }
};