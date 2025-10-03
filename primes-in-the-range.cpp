#include <bits/stdc++.h>
#include <cmath>
#include <unordered_map>
using namespace std;

bool isPrime(int n) {

  bool answer = true;
  
  if (n < 2) {
    return false;
  }

  for (size_t i = 2; i < sqrt(n); i++) {
    if (n % i == 0) {
      return false;
    }
  }

  return answer;
}

int main() {
  int q;
  std::cin >> q;

  set<int> answer_set;

  unordered_map<int, bool> hello;

  while (q--) {
    int l, r;
    std::cin >> l >> r; // taking the input
    for (int i = l; i <= r; i++) {
      if (!hello[i] && isPrime(i)) {
        hello[i] = true;
        answer_set.insert(i);
      }
    }
    cout << q << endl;
  }

  vector<int> v(answer_set.begin(), answer_set.end());

  cout << endl << "Here are all the answers" << endl;
  for (int i = 0; i < v.size(); i++) {
    cout << v[i] << endl;
  }
}
