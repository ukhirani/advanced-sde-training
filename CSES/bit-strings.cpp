

#include <bits/stdc++.h>
using namespace std;

int main() {
  int n;
  cin >> n;
  long long unsigned int hello = 1;
  long long unsigned int yello = 1e9 + 7;
  while (n--) {
    hello <<= 1;
    hello %= yello;
  }
  cout << hello;
}
