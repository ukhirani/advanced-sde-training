#include <bits/stdc++.h>
using namespace std;

string reorganizeString(string s) {
  unordered_map<char, int> mp;
  char max_char;
  int max_freq = 0;

  int index = 0;
  for (char c : s) {
    mp[c]++;
    if (mp[c] > max_freq) {
      max_freq = mp[c];
      max_char = c;
    }
  }

  if (max_freq > (s.length() + 1) / 2) {
    return "";
  }


  for (int i = 0; i < max_freq; i ++) {
    s[index] = max_char;
    index+=2;
  }
  mp.erase(max_char);
  // index += 2;

  for (auto hello : mp) {

    for (int i = 0; i < hello.second; i++) {
      s[index] = hello.first;
      index += 2;

      if (index >= s.length()) {
        index = 1;
      }
    }
  }

  return s;
}

int main() {
  string s;
  cout << "please enter the string " << endl;
  cin >> s;
  cout << s << endl;
  return 0;
}
