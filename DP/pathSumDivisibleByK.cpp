/*

Approach:

1. We will use dynamic programming to solve this problem.
2. We will use a 3D dp array to store the number of paths from the current cell
to the bottom-right cell.
3. Keep track of remaining sum of the path.
4. If the remaining sum is 0, then we have found a valid path.
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  const int MOD = 1e9 + 7;
  int solve(int i, int j, int sum, vector<vector<int>> &grid, int k,
            vector<vector<vector<int>>> &dp) {
    if (i >= grid.size() || j >= grid[0].size())
      return 0;
    if (i == grid.size() - 1 && j == grid[0].size() - 1) {
      sum = (sum + grid[i][j]) % k;
      return sum % k == 0; // check if a valid path
    }

    if (dp[i][j][sum] != -1)
      return dp[i][j][sum];

    int down = solve(i + 1, j, (sum + grid[i][j]) % k, grid, k, dp) % MOD;
    int right = solve(i, j + 1, (sum + grid[i][j]) % k, grid, k, dp) % MOD;

    return dp[i][j][sum] = (down + right) % MOD;
  }

public:
  int numberOfPaths(vector<vector<int>> &grid, int k) {
    int m = grid.size();
    int n = grid[0].size();

    int sum = 0;

    vector<vector<vector<int>>> dp(m,
                                   vector<vector<int>>(n, vector<int>(50, -1)));

    return solve(0, 0, sum, grid, k, dp);
  }
};

/*
Test Case:

Input: grid = [[5,2,4],[3,0,5],[0,7,2]], k = 3
Output: 2

Time Complexity: O(m*n*k)
Space Complexity: O(m*n*k)

*/