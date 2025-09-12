
#include <bits/stdc++.h>
using namespace std;



int main(){
    int x = 7;
    int a[10];
    for(int i = 0;i<10;i++){
        a[i] = i + 1;
    }
    int *ptr_a = &a[9];
    cout<< ptr_a[-2] << endl;
    // a[x] = *(a+x) <- this is how basically the [] operator works
    // so basically if ptr_a = &a[9] <- then a[-2] = a[7]
    //
    // now even though we know the size is 10 of the array we can still do this *ptr_a = &a[10]
}
