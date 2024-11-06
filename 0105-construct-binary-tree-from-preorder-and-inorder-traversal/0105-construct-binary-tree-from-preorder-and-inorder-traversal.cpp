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
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) 
    {
        std::unordered_map<int, int> m;
        for (int i = 0; i < inorder.size(); ++i) 
        {
            m[inorder[i]] = i;
        }
        TreeNode* head = new TreeNode(preorder[0]);
        std::stack<TreeNode*> st;
        st.push(head);

        for (int i = 1; i < preorder.size(); i++)
        {
            TreeNode* node = new TreeNode(preorder[i]);
            if (m[preorder[i]] < m[st.top()->val])
            {
                st.top()->left = node;
            }
            else
            {
                TreeNode* parent = nullptr;
                while (!st.empty() && m[preorder[i]] > m[st.top()->val])
                {
                    parent = st.top();
                    st.pop();
                }
                parent->right = node;
            }
            st.push(node);
        }

        return head;
    }
};