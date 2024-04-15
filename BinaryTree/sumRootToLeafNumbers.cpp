class Solution
{
private:
    int solve(vector<int> &path)
    {
        string s = "";
        for (auto it : path)
        {
            s += to_string(it);
        }
        return stoi(s);
    }

private:
    void dfs(TreeNode *root, vector<int> &path, int &sum)
    {
        if (!root)
            return;
        path.push_back(root->val);
        if (!root->left && !root->right)
        {
            sum += solve(path);
            // backtrack
            path.pop_back();
            return;
        }
        dfs(root->left, path, sum);
        dfs(root->right, path, sum);
        // backtrack
        path.pop_back();
        return;
    }

public:
    int sumNumbers(TreeNode *root)
    {
        if (!root)
            return 0;
        vector<int> path;
        int sum = 0;
        dfs(root, path, sum);
        return sum;
    }
};