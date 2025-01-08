class Solution {
public:
    string removeDuplicateLetters(string s) {
        deque<char> d;
        string answer;
        unordered_map<char, int> um;
        unordered_map<char, int> sameLetter;

        for(int i = 0; i < s.size(); ++i)
        {
            um[s[i]] = i;
        }

        for(int i = 0; i < s.size(); ++i)
        {
            while(!d.empty() && um[d.back()] > i && s[i] < d.back() && sameLetter[s[i]] < 1)
            {
                --sameLetter[d.back()];
                d.pop_back();
            }

            if(sameLetter[s[i]] < 1 )
            {
                d.push_back(s[i]);
                ++sameLetter[s[i]];
            }
        }

        while(!d.empty())
        {
            answer.push_back(d.front());
            d.pop_front();
        }
        
        return answer;
    }
};