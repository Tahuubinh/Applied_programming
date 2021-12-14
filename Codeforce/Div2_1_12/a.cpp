#include <bits/stdc++.h>
using namespace std;
#define endl '\n';
#define pii pair<int, int>
using ll = long long;
using ull = unsigned long long;
int t;

int x1, x2, p1, p2;

int cntdigit(int x){
    if (1 <= x && x < 10){
        return 1;
    }
    else if (10 <= x && x < 100){
        return 2;
    }
    else if (100 <= x && x < 1000){
        return 3;
    }
    else if (1000 <= x && x < 10000){
        return 4;
    }
    else if (10000 <= x && x < 100000){
        return 5;
    }
    else {
        return 6;
    }
}

int main(){
    ios_base :: sync_with_stdio(0); cin.tie(0); cout.tie(0);
    //cout << cntdigit(99);
    cin >> t;
    while(t--){
        cin >> x1 >> p1 >> x2 >> p2;
        int temp1 = cntdigit(x1) + p1;
        int temp2 = cntdigit(x2) + p2;
        //cout << temp1 << temp2;
        if (temp1 > temp2){
            cout << '>' << endl;
        }
        else if (temp1 < temp2){
            cout << '<' << endl;
        }
        else{
            //cout << 2;
            while (cntdigit(x1) < cntdigit(x2)){
                x1 *= 10;
            }
            while (cntdigit(x1) > cntdigit(x2)){
                x2 *= 10;
            }
            if (x1 == x2){
                cout << '=' << endl;
            }
            else if (x1 > x2){
                cout << '>' << endl;
            }
            else{
                cout << '<' << endl;
            }
        }
    }

    
    return 0;
}
