#include <algorithm>
#include <bits/stdc++.h>
using namespace std;

int main() {
  string s;
  cout << "Enter the string \n";

  s = " asdf jjflkasdjf adfjalsdkfjalsdf a sdf asdfkj fasdf";

  int start = 0, end = 0;

  for (int i = 0; i < s.size(); i++) {
    if (s[i] == ' ') {
      end = i - 1;
      if (end >= 0) {
        sort(s.begin() + start, s.begin() + end);
      }
      start = i + 1;
    }
  }
  while (s[start] == ' ') {
    start++;
  }

  sort(s.begin() + start, s.end());

  cout << s;
}
