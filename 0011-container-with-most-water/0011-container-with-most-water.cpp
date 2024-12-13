class Solution {
public:
    int maxArea(vector<int>& height) {
        int answer{};
        int left{}, right = height.size() - 1;
        int minHeight{}, width;

        while(left < right)
        {
            width = right - left;
            if(height[left] < height[right])
            {
                minHeight = height[left];
                ++left;
            }
            else
            {
                minHeight = height[right];
                --right;
            }

            if(minHeight * width > answer)
            {
                answer = minHeight * width;
            }
        }
        
        return answer;
    }
};