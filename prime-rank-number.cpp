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
      std::cout<<i<<endl;
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
