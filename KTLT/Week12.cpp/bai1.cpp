#include <bits/stdc++.h>
using namespace std;

int dequy(int n){
    if (n == 0){
        return 1;
    }
    return n * dequy(n - 1);
};

int main(){
    int n = 648;
    while (n >= 10){
        n = n/10 + n%10;
    }
    cout << n;
    return 0;
}