#include <bits/stdc++.h>
using namespace std;


int* calSquare(int x){
    static int a[2];
    a[0] = x * 4;
    a[1] = x*x;
    return a;
}

int main(){
    int* a = calSquare(5);
    cout << "parameter: " << a[0] << endl;
    cout << "area: " << a[1] << endl;
    
    return 0;
}
