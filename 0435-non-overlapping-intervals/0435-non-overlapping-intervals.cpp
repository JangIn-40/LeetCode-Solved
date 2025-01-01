class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end(), [](vector<int>& a, vector<int>& b){
            if(a[0] == b[0])
            {
                return a[1] < b[1];
            }
            else
            {
                return a[0] < b[0];
            }
        });

        for(auto& e : intervals)
        {
            for(auto& ele : e )
            {
                cout << ele << ' ';
            }
            cout << endl;
        }

        int end = intervals[0][1];
        int answer{};
        for(int i = 1; i < intervals.size(); ++i)
        {
            if(end > intervals[i][0])
            {
                ++answer;
                end = min(intervals[i][1], end);
            }
            else
            {
                end = intervals[i][1];
            }
        }

        return answer;
    }
};