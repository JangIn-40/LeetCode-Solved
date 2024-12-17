class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int idx;
        int remain;
        for(int i = 0; i < gas.size(); ++i)
        {
            remain = gas[i] - cost[i];
            if(remain >= 0)
            {
                int j;
                for(j = i + 1; j < gas.size() && remain >= 0; ++j)
                {
                    remain += gas[j] - cost[j];
                }
                --j;
                
                if(remain >= 0)
                {
                    for(j = 0; j < i && remain >= 0; ++j)
                    {
                        remain += gas[j] - cost[j];
                    }
                }

                if(remain >= 0)
                {
                    return i;
                }
                
                if(j < i)
                {
                    return -1;
                }
                else
                {
                    i = j;
                }
            }
        }

        return -1;
    }
};