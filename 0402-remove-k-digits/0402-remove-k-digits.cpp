class Solution {
public:
    string removeKdigits(string num, int k) {
        deque<char> s;
        string answer;

        for(auto& n : num)
        {
            while(!s.empty() && k > 0 && s.back() > n)
            {
                s.pop_back();
                --k;
            }

            s.push_back(n);
        }

        while(k > 0 && !s.empty())
        {
            s.pop_back();
            --k;
        }

        while(!s.empty())
        {
            answer.push_back(s.front());
            s.pop_front();
        }

        int len{};
        while(answer[len] == '0')
        {
            ++len;
        }

        if(len == answer.size())
        {
            return "0";
        }
        else
        {
            return answer.substr(len);
        }

    }
};