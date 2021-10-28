#include <bits/stdc++.h>
using namespace std;

int X = 4;
int a[3][4];

void MyFunc(int a[][3]){
    cout << a[1][1];
}

int main(){
    int a[][3] = {{9, 11, 13}, {1, 3, 5}};
    MyFunc(a);
    
    return 0;
}

