class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> adjList(numCourses);
        vector<int> topologyCount(numCourses);

        for(const auto& vec : prerequisites)
        {
            adjList[vec[1]].push_back(vec[0]);
            ++topologyCount[vec[0]];
        }

        queue<int> q;
        for(int i = 0; i < numCourses; ++i)
        {
            if(topologyCount[i] == 0)
            {
                q.push(i);
            }
        }

        vector<int> order;
        for(int i = 0; i < numCourses; ++i)
        {
            if(q.empty())
            {
                return {};
            }
            
            int f = q.front();
            q.pop();

            order.push_back(f);

            for(auto& vec : adjList[f])
            {
                if(--topologyCount[vec] == 0)
                {
                    q.push(vec);
                }
            }
        }

        return order;
    }
};