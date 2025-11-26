#include <algorithm>
#include <bits/stdc++.h>
#include <vector>

using namespace std;

bool bs(vector<long long> &barn, long long cows, long long input) {

  long long x = 1;
  long long prev = barn[0];

  for (long long i = 1; i < barn.size(); i++) {
    long long curr = barn[i];
    if ((curr - prev) >= input) {
      x++;
      prev = curr;
    }
  }

  return cows <= x;
}

void solve() {
  long long size, cows;
  cin >> size >> cows;
  vector<long long> barn(size);

  for (long long i = 0; i < size; i++) {
    long long temp;
    cin >> temp;
    barn[i] = temp;
  }

  sort(barn.begin(), barn.end());

  long long left = 0;
  long long right = INT_MAX;
  long long answer = INT_MIN;

  while (left <= right) {
    long long mid = left + (right - left) / 2;
    if (bs(barn, cows, mid)) {
      answer = max(answer, mid);
      left = mid + 1;
    } else {
      right = mid - 1;
    }
  }

  cout << answer << endl;
}

int main() {

  long long q;
  cin >> q;
  while (q--) {
    solve();
  }
}
