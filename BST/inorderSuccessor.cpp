class Solution
{
private:
    void dfs(TreeNode *root, TreeNode *p, vector<TreeNode *> &v)
    {
        if (!root)
            return;
        // inorder
        dfs(root->left, p, v);
        v.push_back(root);
        dfs(root->right, p, v);
    }

public:
    TreeNode *inorderSuccessor(TreeNode *root, TreeNode *p)
    {
        TreeNode *result = NULL;
        vector<TreeNode *> v;
        dfs(root, p, v);
        for (int i = 0; i < v.size(); i++)
        {
            if (v[i] == p)
            {
                if (i != v.size() - 1)
                {
                    return v[i + 1];
                }
                else
                {
                    return NULL;
                }
            }
        }
        return NULL;
    }
};