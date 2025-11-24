/*

Approach:

1. Create a function to find the leftmost right child of a node.
2. Create a function to delete a node from the BST.
3. In the function, if the node is a leaf node, return NULL.
4. Otherwise, create a new node with the value of the node and recursively
delete the left and right subtrees.
5. Return the root node.

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
  TreeNode *findChild(TreeNode *root) {
    if (!root)
      return NULL;

    while (root->right) {
      root = root->right;
    }
    return root;
  }

public:
  TreeNode *helper(TreeNode *root) {
    if (!root)
      return NULL;

    if (!root->left) {
      return root->right;
    } else if (!root->right) {
      return root->left;
    }

    TreeNode *rightChild = root->right;
    TreeNode *leftMostRightChild = findChild(root->left);

    leftMostRightChild->right = rightChild;

    return root->left;
  }

public:
  TreeNode *deleteNode(TreeNode *root, int key) {
    if (!root)
      return NULL;

    if (root->val == key) {
      return helper(root);
    }

    TreeNode *dummy = root;

    while (root) {
      if (root->val > key) {
        if (root->left && root->left->val == key) {
          root->left = helper(root->left);
        } else {
          root = root->left;
        }
      } else {
        if (root->right && root->right->val == key) {
          root->right = helper(root->right);
        } else {
          root = root->right;
        }
      }
    }
    return dummy;
  }
};

/*

Test Case:

Input: root = [5,3,6,2,4,null,7], key = 3
Output: [5,4,6,2,null,null,7]

Time Complexity: O(h)
Space Complexity: O(h)

*/