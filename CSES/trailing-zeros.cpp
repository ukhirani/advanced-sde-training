#include <bits/stdc++.h>
using namespace std;

int findFives(int n){
    int answer = 0;
    while(n%5 == 0){
        answer++;
        n = n/5;
    }
    return answer;
}

int main(){

    int n;
    int answer = 0;
    int i = 5;
    int multiple = 1;
    cin >> n;


    if(n<5){
        cout<< answer;
        return 0;
    }
    

    while (i<=n) {

        if(multiple%5 == 0){
            answer += findFives(multiple);
        }
        multiple++;
        answer++;
        i+=5;
    }

    cout << answer;
    


}
