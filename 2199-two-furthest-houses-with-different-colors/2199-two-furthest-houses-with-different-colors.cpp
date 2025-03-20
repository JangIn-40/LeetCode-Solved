class Solution {
public:
    int maxDistance(vector<int>& colors) {
        int n = colors.size();
        int p{}, q = n -1;
        int maxDist{};
        
        while(0 < q)
        {
            if(colors[0] != colors[q])
            {
                int dist = abs(0 - q);
                if(maxDist < dist)
                {
                    maxDist = dist;
                }
                break;
            }
            --q;
        }

        while(p < n - 1)
        {
            if(colors[p] != colors[n - 1])
            {
                int dist = abs(p - (n - 1));
                if(maxDist < dist)
                {
                    maxDist = dist;
                }
                break;
            }
            ++p;
        }

        return maxDist;
    }
};