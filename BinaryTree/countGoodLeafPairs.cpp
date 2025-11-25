/*

Approach:

1. Build a graph from the tree and store the leaf nodes.
2. For each leaf node, perform a BFS to find all nodes within the given
distance.
3. Count the number of good leaf pairs.

*/

#include <bits/stdc++.h>
using namespace std;

struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode(int x) {
    val = x;
    left = NULL;
    right = NULL;
  }
};
class Solution {
public:
  void buildGraph(TreeNode *root, TreeNode *prev,
                  unordered_map<TreeNode *, vector<TreeNode *>> &adj,
                  unordered_set<TreeNode *> &leaves) {
    if (!root)
      return;

    if (!root->left && !root->right)
      leaves.insert(root);

    if (prev) {
      adj[root].push_back(prev);
      adj[prev].push_back(root);
    }
    buildGraph(root->left, root, adj, leaves);
    buildGraph(root->right, root, adj, leaves);

    return;
  }

public:
  int countPairs(TreeNode *root, int distance) {
    if (!root)
      return 0;

    // build and unidrected graph from tree and store the leaf nodes
    unordered_map<TreeNode *, vector<TreeNode *>> adj;
    unordered_set<TreeNode *> leaves;

    buildGraph(root, NULL, adj, leaves);
    int count = 0;

    for (auto &leaf : leaves) {
      queue<TreeNode *> q;
      q.push(leaf);
      int level = 0;
      unordered_set<TreeNode *> vis;
      vis.insert(leaf);

      while (!q.empty() && level <= distance) {
        int size = q.size();
        while (size--) {
          auto node = q.front();
          q.pop();

          if (node != leaf && leaves.count(node)) {
            count++;
          }

          for (auto &it : adj[node]) {
            if (!vis.count(it)) {
              q.push(it);
              vis.insert(it);
            }
          }
        }
        level++;
      }
    }
    return count / 2;
  }
};

/*

Test Case:

Input: root = [1,2,3,null,4], distance = 3
Output: 1

Time Complexity: O(n)
Space Complexity: O(n)

*/