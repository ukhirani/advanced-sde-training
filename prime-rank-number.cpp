//question description
//if there is a list of any prime numbers starting from 2,3,5,7 and so on. the index of the prime number on the list is called it's 'rank'
// you need to find the count of numbers such that the rank and it's reverse say r1 and r2, the number at these ranks r1 and r2, you can make one out of other by reversing them
// let's say w1 and w2 are the numbers at r1 and r2 where r1 <- reverse -> r2  then w1 <- revers -> w2

#include <bits/stdc++.h>
using namespace std;


int reverseNumber(int n){
	int revNum = 0;
	while(n > 0){
		int ld = n % 10;
		revNum = (revNum * 10) + ld;
		n = n / 10;
	}
	return revNum;
}


int main() {
  int answer = 0;
  int n = 1e3;

  vector<bool> flags(n + 1, true);
  int count = 0;
  vector<int> v;
  v.push_back(0);

  for (int i = 2; i < n; i++) {
    if (flags[i]) {
      v.push_back(i);
      cout<<i<<endl;
      for (int j = 2; (j * i) < n; j++) {
        flags[j * i] = false;
      }
    }
  }


 for(int i = 12;i<v.size();i++){
     int reverse_rank = reverseNumber(i);
     int reverse_number;
     if(i==reverse_rank){
         continue;
     }
     if(reverse_rank>=v.size()){
         continue;
     }
     reverse_number = reverseNumber(v[reverse_rank]);
     if(reverse_number == v[i]){
         answer++;
     }
 }

 cout<<answer<<endl;

}
