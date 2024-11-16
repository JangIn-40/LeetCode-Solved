class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int n = matrix.size() / 2;
        int start{}, end = matrix[0].size() - 1;

        while(start < end)
        {
            std::vector<int> temp;
            for (int i = start; i <= end; ++i)
            {
                temp.push_back(matrix[start][i]);
            }

            for (int i = start, j = 0; i < end; ++i, ++j)
            {
                matrix[start][end - j] = matrix[i][start];
                matrix[i][start] = matrix[end][i];
                matrix[end][i] = matrix[end - j][end];
                matrix[end - j][end] = temp[end - i];
            }

            ++start;
            --end;
        }
    }
};