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
    /*void trav(vector<int>& res, TreeNode* r)
    {
        if (r->left)
            trav(res, r->left);
        res.push_back(r->val);
        if (r->right)
            trav(res, r->right);
    }*/
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> res;
        /*
        if (root!=nullptr)
            trav(res, root);
        return res;
        */
        stack<TreeNode*> s;
        while (root || !s.empty())
        {
            while (root)
            {
                s.push(root);
                root=root->left;
            }
            root=s.top();
            s.pop();
            res.push_back(root->val);
            root=root->right;
        }
        return res;
    }
};
