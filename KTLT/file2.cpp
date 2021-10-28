#include <bits/stdc++.h>
using namespace std;

int X = 4;

int& MyFunc(){
    return X;
}

int main(){
    cout << "X=" << X << endl;
    cout << "X=" << MyFunc() << endl;
    MyFunc() = 20;
    cout << "X=" << X << endl;
    
    return 0;
}

