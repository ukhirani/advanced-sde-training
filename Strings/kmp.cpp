#include <bits/stdc++.h>
#include <vector>
using namespace std;
int main(int argc, char *argv[]) {
  string s = "aabaacaadaabaaba";
  string pat = "aaba";

  // conpattructing lps
  int len = 0, i = 1;
  int n = pat.size();
  vector<int> lps(n, 0);
  while (i < n) {
    if (pat[i] == s[len]) {
      lps[i++] = ++len;
    } else {
      if (len == 0) {
        lps[i++] = 0;
      } else {
        len = lps[len - 1];
      }
    }
  }

  i = 0; // this is the pointer that we are using for the main string indexing
  int j = 0; // this will be the lps index
  int pat_size = pat.size();
  int txt_size = s.size();
  vector<int> found;

  while (i < txt_size) {

    if (s[i] == pat[j]) {
      i++;
      j++;
    } else {
      if (j == 0) {
        i++;
      } else {
        j = lps[j - 1];
      }
    }

    if (j == pat_size) {
      j = lps[j - 1];
      found.push_back(i - pat_size);
    }
  }

  cout << "here are the indexes we found " << pat << "  in " << s << endl;
  for (int x : found) {
    cout << x << "\t";
  }

  return 0;
}
