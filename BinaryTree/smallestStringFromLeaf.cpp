class Solution
{
private:
    void dfs(TreeNode *root, string &result, string path)
    {
        if (!root)
            return;
        path.push_back(root->val + 'a');
        if (!root->left && !root->right)
        {
            string temp = path;
            reverse(temp.begin(), temp.end());
            if (result == "" || result > temp)
            {
                result = temp;
            }
            // backtrack
            path.pop_back();
            return;
        }
        dfs(root->left, result, path);
        dfs(root->right, result, path);
        // backtrack
        path.pop_back();
        return;
    }

public:
    string smallestFromLeaf(TreeNode *root)
    {
        string result = "";
        string path = "";
        dfs(root, result, path);
        return result;
    }
};