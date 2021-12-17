#include <iostream>

using namespace std;

struct SP{
    double real;
    double img;
    SP operator + (SP C1){
        SP tmp;
        tmp.real = C1.real + real;
        tmp.img = C1.img + img;
        return tmp;
    }
    SP operator - (){
        SP tmp;
        tmp.real = - real;
        tmp.img = - img;
        return tmp;
    }
//    SP& operator = (SP& c){
//        return c;
//    }
    SP operator ++ (){
        ++real;
        ++img;
        return *this;
    }
};

SP setSP(double real, double img){
    SP tmp;
    tmp.real = real;
    tmp.img = img;
    return tmp;
}
//SP operator + (SP C1, SP C2){
//    SP tmp;
//    tmp.real = C1.real + C2.real;
//    tmp.img = C1.img + C2.img;
//    return tmp;
//}
SP operator - (SP C1, SP C2){
    SP tmp;
    tmp.real = C1.real - C2.real;
    tmp.img = C1.img - C2.img;
    return tmp;
}

void displaySP(SP c){
    cout << "(" << c.real << "," << c.img << ")";
}
int main(){
    SP C1, C2, C3, C4;
    C1 = setSP(1.0, 2.0);
    C2 = setSP(-3.0,4.0);
    cout << "\nSo phuc thu nhat:";
    displaySP(C1);
    cout << "\nSo phuc thu hai:";
    displaySP(C2);
    C3 = C1 + C2;
    C4 = C1 - C2;
    //SP C5 = C3
    cout << "\nTong hai so phuc nay:";
    displaySP(C3);
    cout << "\nHieu hai so phuc nay:";
    displaySP(C4);
    cout << "\n++C1: ";
    displaySP(C1);
    return 0;
}
