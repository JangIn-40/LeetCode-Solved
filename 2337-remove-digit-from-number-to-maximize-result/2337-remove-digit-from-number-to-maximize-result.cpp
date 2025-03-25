class Solution {
public:
    string removeDigit(string number, char digit) {
        priority_queue<string> pq;

        for(int i = 0; i < number.size(); ++i)
        {
            if(number[i] == digit)
            {
                string comp = number.substr(0, i) + number.substr(i + 1);
                pq.push(comp);
            }
        }

        return pq.top();
    }
};