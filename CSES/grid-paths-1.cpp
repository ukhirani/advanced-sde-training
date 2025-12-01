#include <bits/stdc++.h>
using namespace std;

int hello(vector<vector<int>> &grid, int x, int y, int n,
          vector<vector<int>> &dp) {

  if (x >= n || y >= n || grid[x][y] == 1) {
    return 0;
  }
  if (dp[x][y] != -1) {
    return dp[x][y];
  }
  if (x == (n - 1) && y == x) {
    return 1;
  }
  int right = hello(grid, x + 1, y, n, dp);
  int left = hello(grid, x, y + 1, n, dp);

  return (dp[x][y] = (right + left) % int(1e9 + 7));
}
int main() {

  int n;
  cin >> n;
  char input;
  vector<vector<int>> grid(n, vector<int>(n, 0));
  vector<vector<int>> dp(n, vector<int>(n, -1));

  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      cin >> input;
      if (input == '*') {
        grid[i][j] = 1;
      }
    }
  }

  cout << hello(grid, 0, 0, n, dp);
}
