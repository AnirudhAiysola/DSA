/*
Approach:

1. Create a function to check if a subgrid is a leaf node.
2. Create a function to build the quadtree from the grid.
3. In the function, if the subgrid is a leaf node, return a new node with the
value of the subgrid.
4. Otherwise, create a new node with the value of the subgrid and recursively
build the left, right, top, and bottom subtrees.
5. Return the root node.
*/

#include <bits/stdc++.h>
using namespace std;

struct Node {
  int val;
  bool isLeaf;
  Node *topLeft;
  Node *topRight;
  Node *bottomLeft;
  Node *bottomRight;
  Node(int x, bool isLeaf) {
    val = x;
    isLeaf = isLeaf;
    topLeft = NULL;
    topRight = NULL;
    bottomLeft = NULL;
    bottomRight = NULL;
  }
};
class Solution {
public:
  bool check(vector<vector<int>> &grid, int x, int y, int n) {
    int start = grid[x][y];

    for (int i = x; i < x + n; i++) {
      for (int j = y; j < y + n; j++) {
        if (grid[i][j] != start)
          return false;
      }
    }
    return true;
  }

public:
  Node *solve(vector<vector<int>> &grid, int x, int y, int n) {
    if (check(grid, x, y, n)) {
      return new Node(grid[x][y], true);
    } else {
      Node *root = new Node(1, false);
      root->topLeft = solve(grid, x, y, n / 2);
      root->topRight = solve(grid, x, y + n / 2, n / 2);
      root->bottomLeft = solve(grid, x + n / 2, y, n / 2);
      root->bottomRight = solve(grid, x + n / 2, y + n / 2, n / 2);

      return root;
    }
  }

public:
  Node *construct(vector<vector<int>> &grid) {
    int n = grid.size();

    return solve(grid, 0, 0, n);
  }
};

/*
Test Case:

Input: grid =
[[1,1,1,1,0,0,0,0],[1,1,1,1,0,0,0,0],[1,1,1,1,1,1,1,1],[1,1,1,1,1,1,1,1],[1,1,1,1,0,0,0,0],[1,1,1,1,0,0,0,0],[1,1,1,1,0,0,0,0],[1,1,1,1,0,0,0,0]]
Output: [[0,1],[1,0],[1,1],[1,1]]

Time Complexity: O(n^2)
Space Complexity: O(n^2)

*/