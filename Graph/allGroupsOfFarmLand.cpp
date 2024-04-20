class Solution
{
private:
    void dfs(int i, int j, int &p, int &q, vector<vector<int>> &vis, vector<vector<int>> &land)
    {
        if (i < 0 || i >= land.size() || j < 0 || j >= land[0].size() || vis[i][j] || !land[i][j])
            return;
        p = max(p, i);
        q = max(q, j);
        vis[i][j] = 1;
        dfs(i + 1, j, p, q, vis, land);
        dfs(i - 1, j, p, q, vis, land);
        dfs(i, j + 1, p, q, vis, land);
        dfs(i, j - 1, p, q, vis, land);
        return;
    }

public:
    vector<vector<int>> findFarmland(vector<vector<int>> &land)
    {
        int m = land.size();
        int n = land[0].size();
        vector<vector<int>> vis(m, vector<int>(n, 0));
        vector<vector<int>> result;
        // dfs
        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (land[i][j] && !vis[i][j])
                {
                    vector<int> v;
                    v.push_back(i);
                    v.push_back(j);
                    int p = i, q = j;
                    dfs(i, j, p, q, vis, land);
                    v.push_back(p);
                    v.push_back(q);
                    result.push_back(v);
                }
            }
        }
        return result;
    }
};