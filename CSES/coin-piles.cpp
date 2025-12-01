
#include <bits/stdc++.h>
using namespace std;

int main() {
  int n;
  cin >> n;
  while (n--) {
    int a, b;
    cin >> a >> b;
    if ((a + b == 0) || ((a + b) % 3 == 0 && ((a != 0) && (b != 0)) &&
                         ((a <= 2 * b) && (b <= 2 * a)))) {
      cout << "YES" << endl;
    } else {

      cout << "NO" << endl;
    }
  }
}
