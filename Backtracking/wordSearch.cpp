class Solution
{
private:
    bool dfs(int i, int j, vector<vector<char>> &board, string &word, int index)
    {
        // out of bounds check
        if (i < 0 || i >= board.size() || j < 0 || j >= board[0].size())
            return false;
        // if not equal character
        if (board[i][j] != word[index])
            return false;
        char ch = board[i][j];
        // return true if reached last index
        if (index == word.size() - 1)
            return true;
        board[i][j] = '#';
        if (dfs(i + 1, j, board, word, index + 1) || dfs(i - 1, j, board, word, index + 1) || dfs(i, j + 1, board, word, index + 1) || dfs(i, j - 1, board, word, index + 1))
        {
            return true;
        }
        // backtrack
        board[i][j] = ch;
        return false;
    }

public:
    bool exist(vector<vector<char>> &board, string word)
    {
        int m = board.size();
        int n = board[0].size();

        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (board[i][j] == word[0])
                {
                    if (dfs(i, j, board, word, 0))
                        return true;
                }
            }
        }
        return false;
    }
};