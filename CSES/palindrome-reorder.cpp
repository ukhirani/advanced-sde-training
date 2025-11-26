#include <algorithm>
#include <bits/stdc++.h>
#include <unordered_map>
using namespace std;
int main() {

  // inputtting the string from the user
  string s;
  cin >> s;

  // populating the frequency map
  unordered_map<char, int> mp;
  for (char c : s) {
    mp[c]++;
  }

  int count_ones = 0;
  char that_one_character;

  for (auto [first, second] : mp) {
    if (second % 2) {
      count_ones++;
      that_one_character = first;
    }

    if (count_ones > 1) {
      cout << "NO SOLUTION" << endl;
      return 0;
    }
  }

  string pseudo_string = "";
  string answer = "";

  for (auto [first, second] : mp) {
    for (int i = 0; i < (second / 2); i++) {
      pseudo_string += first;
    }
  }

  string reverse_string = pseudo_string;
  reverse(reverse_string.begin(), reverse_string.end());

  if (count_ones) {
    pseudo_string += that_one_character;
  }

  cout << (pseudo_string + reverse_string) << endl;
}
