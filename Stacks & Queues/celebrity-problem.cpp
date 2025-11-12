#include <bits/stdc++.h>
class Solution {
public:
  int celebrity(vector<vector<int>> &mat) {
    int n = mat.size();
    int celeb_col = 0;
    for (int i = 0; i < n; i++) {

      int row_sum = 0;

      for (int j = 0; j < n; j++) {
        if (mat[i][j] == 1) {
          celeb_col = j;
        }
        row_sum += mat[i][j];
      }

      if (row_sum == 1) {

        int col_sum = 0;

        for (int k = 0; k < n; k++) {
          col_sum += mat[k][celeb_col];
        }

        if (col_sum == n) {
          return i;
        }
      }
    }
    return -1;
  }
};
