#include <bits/stdc++.h>
using namespace std;

long long sieve(long long n) {

  long long count = 0;

  vector<long long> primes;
  vector<long long> booleans(n + 1, 1);

  for (long long i = 2; i < booleans.size(); i++) {
    if (booleans[i] == 0) continue;

    primes.push_back(i);

    for (long long j = i * i; j <= n; j += i) {
      booleans[j] = 0;
    }
  }

  cout << "These are the numbers that are magical" << endl;

  for (long long i = 1; i < primes.size(); i++) {
    primes[i] += primes[i - 1];
    if (primes[i] >= booleans.size()) break;
    if (booleans[primes[i]] == 1) {
      cout << primes[i] << "\t";
      count++;
    };
  }
  cout << endl;

  return count;
}

int main() {

  long long n;
  cin >> n;

  long long result = sieve(n);


  cout << endl << "This is the answer : " << result << endl;
}
