/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    bool isSameTree(TreeNode* p, TreeNode* q) {
        if(!p && !q)
        {
            return true;
        }
        else if(!p && q || p && !q)
        {
            return false;
        }
        stack<TreeNode*> pStack, qStack;

        pStack.push(p);
        qStack.push(q);

        while(!pStack.empty() && !qStack.empty())
        {
            TreeNode* currentP = pStack.top();
            TreeNode* currentQ = qStack.top();
            pStack.pop();
            qStack.pop();

            if(currentP->val != currentQ->val)
            {
                return false;
            }
            else if((currentP->left && !currentQ->left) || (!currentP->left && currentQ->left) ||
                        (currentP->right && !currentQ->right) || (!currentP->right && currentQ->right))
            {
                return false;
            }

            if(currentP->left)
            {
                pStack.push(currentP->left);
            }
            if(currentQ->left)
            {
                qStack.push(currentQ->left);
            }
            if(currentP->right)
            {
                pStack.push(currentP->right);
            }
            if(currentQ->right)
            {
                qStack.push(currentQ->right);
            }
        }

        if(!pStack.empty() || !qStack.empty())
        {
            return false;
        }

        return true;
    }
};