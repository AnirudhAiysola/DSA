class Solution
{
private:
    void dfs(int i, int j, vector<vector<int>> &vis, vector<vector<char>> &grid)
    {
        if (i < 0 || i >= grid.size() || j < 0 || j >= grid[0].size() || vis[i][j] || grid[i][j] == '0')
            return;
        vis[i][j] = 1;
        dfs(i + 1, j, vis, grid);
        dfs(i - 1, j, vis, grid);
        dfs(i, j + 1, vis, grid);
        dfs(i, j - 1, vis, grid);
        return;
    }

public:
    int numIslands(vector<vector<char>> &grid)
    {
        int m = grid.size();
        int n = grid[0].size();
        int ans = 0;
        vector<vector<int>> vis(m, vector<int>(n, 0));
        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (grid[i][j] == '1' && !vis[i][j])
                {
                    dfs(i, j, vis, grid);
                    ans++;
                }
            }
        }
        return ans;
    }
};