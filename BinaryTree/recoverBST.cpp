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
  TreeNode *prev = NULL;
  TreeNode *first = NULL;
  TreeNode *mid = NULL;
  TreeNode *second = NULL;

  void solve(TreeNode *root) {
    if (!root)
      return;

    /*
    Inorder travel of BST process the nodes in sorted order
    */
    solve(root->left);

    if (prev && root->val < prev->val) {
      if (first && mid) {
        second = root;
      } else {
        first = prev;
        mid = root;
      }
    }
    prev = root;
    solve(root->right);
  }
  void recoverTree(TreeNode *root) {
    solve(root);
    if (first && second) {
      swap(first->val, second->val);
    } else if (first && mid) {
      swap(first->val, mid->val);
    }
  }
};

int main() {
  Solution s;

  TreeNode *root = new TreeNode(1);
  root->left = new TreeNode(3);
  root->right = new TreeNode(2);

  s.recoverTree(root);

  return 0;
}