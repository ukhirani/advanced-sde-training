#include <bits/stdc++.h>
using namespace std;
int main(int argc, char *argv[]) {
  string s = "aabaacaadaabaaba";
  // conpattructing lps
  int len = 0, i = 1;
  int n = s.size();
  vector<int> lps(n, 0);
  while (i < n) {
    if (s[i] == s[len]) {
      lps[i++] = ++len;
    } else {
      if (len == 0) {
        lps[i++] = 0;
      } else {
        len = lps[len - 1];
      }
    }
  }
  cout << "Here is the LPS array constructed" << endl;
  for (int x : lps) {
    cout << x << "\t" << endl;
  }
  return 0;
}
