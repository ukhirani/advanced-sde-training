#include <bits/stdc++.h>
#include <cmath>
using namespace std;

void solve(int x, int n) {
  //  int bit = mask & x;
  int carry = 0;
  for (int i = n; i >= 0; i--) {
    int mask = 1 << i;
    int bit = mask & x;
    cout << (carry ^ (bit >> i));
    carry = (bit >> i);
  }
  cout << endl;
}

int main() {
  int n;
  cin >> n;
  n = 1 << n;
  n--;

  int num_of_bits = floor(log2(n)) + 1;

  for (int i = 0; i <= n; i++) {
    solve(i, num_of_bits - 1);
  }
}
