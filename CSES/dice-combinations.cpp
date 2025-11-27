#include <bits/stdc++.h>
#include <vector>
using namespace std;

void helper(vector<int> &dice, int &answer, int n, int index,
            vector<vector<int>> &dp) {
  if (index == 6) {
    return;
  }
  if (n == 0) {
    answer++;
    answer = (answer % int(1e9 + 7));
    return;
  }
  if (n < 0)
    return;

  if (dp[n][index] != -1) {
    answer += dp[n][index];
    answer = (answer % int(1e9 + 7));
    return;
  }

  // take
  helper(dice, answer, n - dice[index], 0, dp);
  // not-take
  helper(dice, answer, n, index + 1, dp);

  dp[n][index] = answer;
}

int main() {
  int n;
  cin >> n;

  // probably 2d dp with dp on sum and index
  vector<int> dummy(6, -1);
  vector<vector<int>> dp(n + 1, dummy);

  int answer = 0;
  vector<int> dice = {1, 2, 3, 4, 5, 6};
  helper(dice, answer, n, 0, dp);

  cout << answer << endl;
}
