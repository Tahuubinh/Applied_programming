#include <bits/stdc++.h>
using namespace std;

int calSquarePos(int x, int y){
    if (y == 0){
        return 1;
    }
    if (y % 2){
        return x * calSquarePos(x, y/2) * calSquarePos(x, y/2);
    }
    return calSquarePos(x, y/2) * calSquarePos(x, y/2);
}

void printSquare(int x, int y){
    if (y == 0){
        cout << 0;
    } 
    else if (y > 0){
        cout << calSquarePos(x, y);
    }
    else {
        cout << (double) 1/calSquarePos(x, -y);
    }
}

int main(){
    int x, y;
    cin >> x >> y;
    printSquare(x, y);

    system("pause");
    return 0;
}
