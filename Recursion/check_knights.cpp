#include <bits/stdc++.h>
#include <vector>
using namespace std;

class Solution {
private:
  bool valid(int a, int n) { return (a < n && a >= 0); }
  bool chess(vector<vector<int>> &grid, int x, int y, int val, int n,
             vector<vector<int>> &pairs) {
    if (!(valid(x, n) && valid(y, n))) {
      return false;
    }
    if (val != grid[x][y]) {
      return false;
    }

    if (val == (n * n) - 1) {
      return true;
    }

    bool temp = false;

    for (vector<int> p : pairs) {
      temp |= chess(grid, x + p[0], y + p[1], val + 1, n, pairs);
      if (temp)
        break;
    }

    return temp;
  }

public:
  bool checkValidGrid(vector<vector<int>> &grid) {
    vector<vector<int>> pairs{{2, 1}, {2, -1}, {-2, 1}, {-2, -1},
                              {1, 2}, {1, -2}, {-1, 2}, {-1, -2}};

    int n = grid.size();
    return chess(grid, 0, 0, 0, n, pairs);
  }
};
