class Solution {
public:
    bool isPalindrome(int x) {
        string palindrom = to_string(x);
        int n = palindrom.size();
        for(int i = 0; i < n / 2; ++i)
        {
            if(palindrom[i] != palindrom[n - i - 1])
            {
                return false;
            }
        }
        
        return true;
    }
};