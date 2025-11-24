/*
Approach:

1. Create a map to store the index of each element in the inorder traversal.
2. Create a function to build the tree from the preorder and inorder traversals.
3. In the function, if the start index is greater than the end index, return
NULL.
4. Create a new node with the value at the current index in the preorder
traversal.
5. Find the index of the value in the inorder traversal.
6. Increment the index.
7. Recursively build the left and right subtrees.
8. Return the root node.
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
  TreeNode *solve(int &index, int start, int end, vector<int> &preorder,
                  vector<int> &inorder, unordered_map<int, int> &m) {
    if (start > end)
      return NULL;

    TreeNode *root = new TreeNode(preorder[index]);
    int i = m[preorder[index]];
    index++;

    root->left = solve(index, start, i - 1, preorder, inorder, m);
    root->right = solve(index, i + 1, end, preorder, inorder, m);

    return root;
  }

public:
  TreeNode *buildTree(vector<int> &preorder, vector<int> &inorder) {
    int n = inorder.size();
    int index = 0;

    unordered_map<int, int> m;

    for (int i = 0; i < n; i++) {
      m[inorder[i]] = i;
    }
    return solve(index, 0, n - 1, preorder, inorder, m);
  }
};

/*
Test Case:

Input: preorder = [3,9,20,15,7], inorder = [9,3,15,20,7]
Output: [3,9,20,null,null,15,7]

*/