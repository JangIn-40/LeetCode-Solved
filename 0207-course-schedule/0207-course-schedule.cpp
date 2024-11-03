class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) 
    {
        std::vector<std::vector<int>> adjList(numCourses);
	    std::vector<int> topologyCount(numCourses, 0);

        for (const auto& vec : prerequisites)
        {
            adjList[vec[1]].push_back(vec[0]);
            ++topologyCount[vec[0]];
        }

        std::queue<int> q;

        for (int i = 0; i < numCourses; ++i)
        {
            if (topologyCount[i] == 0)
            {
                q.push(i);
            }
        }

        for (int i = 0; i < numCourses; ++i)
        {
            if (q.empty())
            {
                return false;
            }

            int x = q.front();
            q.pop();

            for (int i = 0; i < adjList[x].size(); ++i)
            {
                int y = adjList[x][i];

                if (--topologyCount[y] == 0)
                {
                    q.push(y);
                }
            }
        }

        return true;
    }
};