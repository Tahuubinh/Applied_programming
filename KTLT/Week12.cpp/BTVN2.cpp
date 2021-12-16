#include <bits/stdc++.h>
using namespace std;

int sum1;

int dequy1(int n){
    if (n == 1) return 1;
    if (n == 2) return 2;
    if (n == 3) return 3;
    int x = dequy1(n - 1) + dequy1(n - 2) + dequy1(n - 3);
    cout << x << ' ';
    return x;
};

int tong1(int n){
    if (n == 1) return 1;
    return tong1(n - 1) + dequy1(n);
}

int main(){
    cout << tong1(10);
    return 0;
}