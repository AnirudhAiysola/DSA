/*
The equations are like an undirected graph, where a==b or b==a is like an
undirected edge, it goes both ways a!=b or b!=a is like an undirected edge, it
goes both ways. So we can use Union Find to solve this problem

Approach:
1. First we will create a Union Find data structure
2. Then we will iterate over the equations and for each equation, if it is of
the form a==b, we will union a and b
3. Then we will iterate over the equations and for each equation, if it is of
the form a!=b, we will check if a and b have the same parent
4. If they have the same parent, we will return false
5. If they don't have the same parent, we will return true
6. If a==b, we will check if they have the same parent, if they don't have the
same parent, we will return false.
7. If we don't find any such case, we will return true
*/

#include <bits/stdc++.h>
using namespace std;

class UnionFind {
public:
  vector<int> parent;
  vector<int> size;

  UnionFind(int n) {
    parent.resize(n);
    size.resize(n, 1);
    for (int i = 0; i < n; i++) {
      parent[i] = i;
    }
  }
  int findParent(int node) {
    if (parent[node] == node) {
      return node;
    }
    return parent[node] = findParent(parent[node]);
  }
  void unionBySize(int u, int v) {
    int up = findParent(u);
    int vp = findParent(v);

    if (up == vp)
      return;
    if (size[up] <= size[vp]) {
      parent[up] = vp;
      size[vp] += size[up];
    } else {
      parent[vp] = up;
      size[up] += size[vp];
    }
    return;
  }
};
class Solution {
public:
  bool equationsPossible(vector<string> &equations) {
    int n = equations.size();
    /*
    I have some mathematical equations, it could be either a==b or a!=b
    form. I need to see whether this equations hold true, if I assign values
    to the equations

    a==b or b==a is like an undirected edge, it goes both ways
    a!=b or b!=a is like an undirecetd edge, it goes both ways
    */
    UnionFind uf(26);

    for (auto &it : equations) {
      int u = it[0] - 'a';
      int v = it[3] - 'a';
      char symbol = it[1];
      if (symbol == '=') {
        uf.unionBySize(u, v);
      }
    }
    // now if they ==, check if they have same parent
    // if they have !=, check if they have different parent

    for (auto &it : equations) {
      int u = it[0] - 'a';
      int v = it[3] - 'a';
      char symbol = it[1];
      int p1 = uf.findParent(u);
      int p2 = uf.findParent(v);
      if (symbol == '=') {
        if (p1 != p2)
          return false;
      } else {
        if (p1 == p2)
          return false;
      }
    }
    return true;
  }
};

/*

Test Cases:
Input: equations = ["a==b","b!=a"]
Output: false


Input: equations = ["a==b","b==a"]
Output: true


Input: equations = ["a==b","b==c","a==c"]
Output: true


Input: equations = ["a==b","b!=c","c==a"]
Output: false


Input: equations = ["c==c","f==f","c==f","b==f"]
Output: true
*/