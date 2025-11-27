#include <algorithm>
#include <bits/stdc++.h>
#include <climits>
#include <vector>
using namespace std;
void helper(vector<int> &inputs, int index, int n, int streak, int &answer,
            vector<vector<int>> &dp) {

  // in case of negative n's
  if (n < 0)
    return;

  // don't let it go out of bounds
  if (index == inputs.size()) {
    return;
  }
  // make answer the minimum of the streak and the current answer in case of
  // success
  if (n == 0) {
    answer = min(answer, streak);
    return;
  }

  if (dp[n][index] != -1)
    return;

  // take
  helper(inputs, index, n - inputs[index], streak + 1, answer, dp);
  dp[n][index] = 1;

  // not take
  helper(inputs, index + 1, n, streak, answer, dp);
}

int main() {
  int q, n;
  cin >> q;
  cin >> n;

  vector<int> inputs(q);

  while (q--) {
    int input;
    cin >> input;
    inputs[q] = input;
  }

  sort(inputs.begin(), inputs.end());
  int answer = INT_MAX;

  // TODO: DP implement karo
  vector<int> dummy(inputs.size(), -1);
  vector<vector<int>> dp(n + 1, dummy);

  helper(inputs, 0, n, 0, answer, dp);

  if (answer == INT_MAX)
    answer = -1;

  cout << answer << endl;
}
