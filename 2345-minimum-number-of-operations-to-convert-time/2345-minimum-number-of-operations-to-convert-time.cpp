class Solution {
public:
    int convertTime(string current, string correct) {

        int min{}, sec{};
        bool isMinute = true;

        for(int i = 0; i < correct.size(); ++i)
        {
            if(!isdigit(correct[i]))
            {
                isMinute = false;
            }

            if(isMinute)
            {
                min = (correct[i] - current[i]) + min * 10;
            }
            else
            {
                sec = (correct[i] - current[i]) + sec * 10;
            }
        }
        
        int time = min * 60 + sec;
        cout << time << endl;
        int count{};

        count += time / 60;
        time %= 60;

        count += time / 15;
        time %= 15;

        count += time / 5;
        time %= 5;

        count += time / 1;
        time %= 1;

        return count;
    }
};