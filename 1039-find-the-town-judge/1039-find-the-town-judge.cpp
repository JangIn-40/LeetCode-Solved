class Solution {
public:
    int findJudge(int n, vector<vector<int>>& trust) {
        vector<vector<int>> graph(n + 1, vector<int>(n + 1, 0));
        for(auto& e : trust)
        {
            int r = e[0];
            int c = e[1];
            ++graph[r][c];
        }

        int nJudge{}, judge{};
        for(int i = 1; i < graph.size(); ++i)
        {
            int count{};
            for(int j = 1; j < graph.size(); ++j)
            {
                if(graph[i][j] != 0)
                {
                    ++count;
                }
            }

            if(count == 0)
            {
                ++nJudge;
                judge = i;
            }
        }

        if(nJudge != 1)
        {
            return -1;
        }
        else
        {
            for(int i = 1; i < graph.size(); ++i)
            {
                if(i != judge && graph[i][judge] != 1)
                {
                    return - 1;
                }

            }
        }

        return judge;
    }
};