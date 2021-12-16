#include <bits/stdc++.h>
using namespace std;
int res;

void move(char from, char to){
    cout << "Move from " << from << " to " << to << endl;
    ++res;
}

void THN(int n, char from, char to, char temp){
    if (n){
        THN(n - 1, from, temp, to);
        move(from, to);
        THN(n - 1, temp, to, from);
    }
}

int main(){
    THN(3, 'A', 'B', 'C');
    cout << res;

    return 0;
}