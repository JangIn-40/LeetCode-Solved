class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> answer;
        vector<int> row;
        answer.push_back(vector<int>(1, 1));

        for(int i = 0; i < numRows; ++i)
        {
            for(int j = 0; i - 1 >= 0 && j < answer[i - 1].size() + 1; ++j)
            {
                int sum{};
                if(j - 1 >= 0)
                {
                    sum += answer[i - 1][j - 1];
                }
                if(j < answer[i - 1].size())
                {
                    sum += answer[i - 1][j];
                }

                row.push_back(sum);
            }

            if(i != 0)
            {
                answer.push_back(row);
                row.clear();
            }

        }

        return answer;
    }
};