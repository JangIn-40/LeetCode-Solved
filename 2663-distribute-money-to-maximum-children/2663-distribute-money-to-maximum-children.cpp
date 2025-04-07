class Solution {
public:
    int distMoney(int money, int children) {
        if(money < children)
        {
            return -1;
        }

        money -= children;

        int countReceiveEightMoney = min(money / 7, children);
        money -= countReceiveEightMoney * 7;
        children -= countReceiveEightMoney;

        if(children == 0 && money > 0)
        {
            --countReceiveEightMoney;
        }

        if(children == 1 && money == 3)
        {
            --countReceiveEightMoney;
        }

        return countReceiveEightMoney;
    }
};