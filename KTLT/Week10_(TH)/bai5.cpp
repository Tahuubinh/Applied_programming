#include <iostream>
#include <ostream>
#include <math.h>
#include <iomanip>

using namespace std;

struct Complex {
    double real;
    double imag;
};

Complex operator + (Complex a, Complex b) {
    Complex tong;
    tong.real = a.real + b.real;
    tong.imag = a.imag + b.imag;
    return tong;
}

Complex operator - (Complex a, Complex b) {
    Complex hieu;
    hieu.real = a.real - b.real;
    hieu.imag = a.imag - b.imag;
    return hieu;
}

Complex operator * (Complex a, Complex b) {
    Complex tich;
    tich.real = a.real * b.real - a.imag * b.imag;
    tich.imag = a.real * b.imag + a.imag * b.real;
    return tich;
}

Complex operator / (Complex a, Complex b) {
    Complex thuong;
    Complex binv;
    binv.real = b.real;
    binv.imag = -b.imag;
    double bsquare = (b * binv).real;
    thuong = a * binv;
    thuong.real /= bsquare;
    thuong.imag /= bsquare;
    return thuong;
}

ostream& operator << (ostream& out, const Complex &a) {
    out << '(' << std::setprecision(2) << a.real << (a.imag >= 0 ? '+' : '-') << std::setprecision(2) << fabs(a.imag) << 'i' << ')';
    return out;
}

int main() {
    double real_a, real_b, img_a, img_b;
    cin >> real_a >> img_a;
    cin >> real_b >> img_b;

    Complex a{real_a, img_a};
    Complex b{real_b, img_b};

    cout << a << " + " << b << " = " << a + b << endl;
    cout << a << " - " << b << " = " << a - b << endl;
    cout << a << " * " << b << " = " << a * b << endl;
    cout << a << " / " << b << " = " << a / b << endl;

    return 0;
}
