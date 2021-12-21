#include <bits/stdc++.h>
using namespace std;
#define endl '\n';
#define pii pair<int, int>
using ll = long long;
using ull = unsigned long long;
int t;



int main(){
    ios_base :: sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> t;
    while(t--){
        string a, s;
        cin >> a >> s;
        string b = "";
        int i = a.size() - 1;
        int j = s.size() - 1;
        int end = 0;
        // string temp = "";
        // temp = temp + s[j - 1] + s[j];
        //b = b + char(stoi(temp) + 48 - a[i] + 48); 
        //int c = stoi(temp);
        // cout << temp << endl;
        // cout << stoi(temp) << endl;

        while (i >= 0 && j >= 0){
            if (s[j] >= a[i]){
                b = char(s[j] - a[i] + 48) + b;
                //cout << b << endl;
                --i;
                --j;
            } else {
                if (!j || s[j - 1] != '1'){
                    cout << -1 << endl;
                    end = 1;
                    break;
                }
                string temp = "";
                temp = temp + s[j - 1] + s[j];
                b = char(stoi(temp) + 48 - a[i] + 48) + b;
                --i;
                j = j - 2; 
            }
        }
        if (end){
            cout << -1 << endl;
            continue;
        }
        if (i < 0){
            while (j >= 0){               
                b = s[j] + b;
                j--;
            }
            while (b[0] == '0'){
                b = b.substr(1, sizeof(b) - 1);
            }
            cout << b << endl;
            continue;
        } 

        if (i >= 0 || j >= 0){
            cout << -1 << endl;
            continue;
        }
        while (b[0] == '0'){
            b = b.substr(1, sizeof(b) - 1);
        }
        cout << b << endl;
    }

    
    return 0;
}
