class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<char, int> characterIndex;

        int maxLength{}, start{};
        for (int i = 0; i < s.size(); ++i)
        {
            auto it = characterIndex.find(s[i]);
            if (it != characterIndex.end() && characterIndex[s[i]] >= start)
            {
                start = it->second + 1;
            }

            characterIndex[s[i]] = i;
            if (maxLength < i - start + 1)
            {
                maxLength = i - start + 1;
            }
        }

        return maxLength;
    }
};