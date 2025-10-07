#include <bits/stdc++.h>
#include <vector>

using namespace std;

void sieve(vector<int> &prime) {
  // vector<int> prime(n + 2, 1);
  int n = prime.size();
  prime[0] = prime[1] = 0;
  for (int i = 2; i < sqrt(n); i++) {
    if (prime[i]==1) {
      for (int j = 2 * i; j < n; j += i) {
        prime[j] = 0;
      }
    }
  }
  // return primqe;
}

int main() {
  
  constexpr int size = 1e6 + 2; 
  vector<int> prefix(size, 0);
  
  int q,max_val;
  max_val = INT_MIN;
  cin >> q;

  while (q--) {
    int l, r;
    cin >> l >> r;
    prefix[l] += 1;
    prefix[r+1] -= 1;
    max_val = max(max_val,r);
  }

  //start time here
  auto start = std::chrono::high_resolution_clock::now();

  int sum = 0;

  for (int i = 0; i<=max_val; i++) {
    prefix[i]+=sum;
    sum = prefix[i];
  }
  int count = 0;

  sieve(prefix);

  cout<<endl<<"Here is the answer"<<endl;
    for (int i = 1; i<=max_val; i++) {

      if(prefix[i]){
        cout<<i<<endl;
        count++;
      }
  
  }
  auto end = std::chrono::high_resolution_clock::now();
  auto elapsed = std::chrono::duration_cast<std::chrono::milliseconds>(end - start);
  std::cout << "Time taken: " << elapsed.count() << " ms" << std::endl;

}
