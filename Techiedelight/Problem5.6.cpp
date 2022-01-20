#include <bits/stdc++.h>
using namespace std;

char cal(double a){
    if (a < 4) return 'F';
    if (4 <= a && a < 5.5) return 'D';
    if (5.5 <= a && a < 7) return 'C';
    if (7 <= a && a < 8.5) return 'B';
    if (8.5 <= a) return 'A';
}

int main(){
    int n;
    cin >> n;
    int A = 0, B = 0, C = 0, D = 0, F = 0;
    while(n--){
        double a;
        cin >> a;
        switch (cal(a)) {
            case 'A': ++A; break;
            case 'B': ++B; break;
            case 'C': ++C; break;
            case 'D': ++D; break;
            case 'F': ++F; break;
            default: break;
        }
    }
    cout << A << " " << B << " " << C << " " << D << " " << F;
}
