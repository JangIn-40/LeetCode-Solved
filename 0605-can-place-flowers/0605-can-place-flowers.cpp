class Solution {
public:
    bool canPlaceFlowers(vector<int>& flowerbed, int n) {
        if(n == 0)
        {
            return true;
        }

        if(flowerbed.size() == 1)
        {
            if(flowerbed[0] == 0 && n == 1)
            {
                return true;
            }
            else
            {
                return false;
            }
        }

        for(int i = 0; i < flowerbed.size(); ++i)
        {
            if(n <= 0)
            {
                break;
            }

            if(flowerbed[i] == 0)
            {
                if((i == 0 && flowerbed[i + 1] == 0) || (i == flowerbed.size() - 1 && flowerbed[i - 1] == 0))
                {
                    flowerbed[i] = 1;
                    --n;
                }
                else if(i > 0 && i < flowerbed.size() && flowerbed[i - 1] == 0 && flowerbed[i + 1] == 0)
                {
                    flowerbed[i] = 1;
                    --n;
                }
            }
        }

        if(n)
        {
            return false;
        }
        else
        {
            return true;
        }
    }
};