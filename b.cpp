#include <bits/stdc++.h>
using namespace std;

int t, in2, in5, in0, in7, temp, af0, af5, res;
string n;
//unsigned long long n;

int main(){
    ios_base :: sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    cin >> t;
    while(t--){
        in0 = af0 = in5 = af5 = 0;
        cin >> n;
        int cnt = 1;
        int len = n.size();
        // cout << len;
        for (int i = len -1; i>=0; --i){
            if (in0 == 0){
                if (n[i] == '0'){
                    in0 = i + 1;
                    // cerr << "in0" << in0 << endl;
                }
            } else{
                if (n[i] == '0' || n[i] == '5'){
                    af0 = i + 1;
                     //cerr << "af0" << af0 << endl;
                    break;
                }
            }
        }

        for (int i = len -1; i>=0; --i){
            if (in5 == 0){
                if (n[i] == '5'){
                    in5 = i + 1;
                    //cerr << "in5" << in5 << endl;
                }
            } else{
                if (n[i] == '2' || n[i] == '7'){
                    af5 = i + 1;
                    //cerr << "af5" << af5 << endl;
                    break;
                }
            }
        }
        res = 100;
        //cout << len << ' ' << af0 << ' ' << af5;
        if (af0 > 0){
            res = min(res, len - af0  - 1);
        }
        if (af5 > 0){
            res = min(res, len - af5  - 1);
        }
        cout << res << '\n';
    }

    
    return 0;
}
