class Solution {
public:
    int minTimeToType(string word) {
        int time{};
        int maxNum = 'z' - 'a' + 1;
        int avg = ('z' - 'a') / 2;
        char ch = 'a';
        
        for(int i = 0; i < word.size(); ++i)
        {
            int currentTime = abs(ch - word[i]);
            if(currentTime > avg)
            {
                time += maxNum - currentTime;
            }
            else
            {
                time += currentTime;
            }

            ch = word[i];
        }

        time += word.size();
        return time;
    }
};