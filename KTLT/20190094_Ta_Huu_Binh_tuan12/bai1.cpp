#include <bits/stdc++.h>
using namespace std;

int n;

int lucas(int n){
    if (!n){
        return 2;
    }
    if (n == 1){
        return 1;
    }
    return lucas(n - 1) + lucas(n - 2);
}

int main(){
    cout << lucas(5);
    return 0;
}
