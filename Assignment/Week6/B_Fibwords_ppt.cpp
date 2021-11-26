#include <bits/stdc++.h>
using namespace std;
#define endl '\n';
using ll = long long;

int n, len, maxind = 1, first, second, fsize, ssize;
ll ans[101], cntans;
string s, fs, sf;
string f[101];

ll cntapp(string src, string s){
    ll cnt = 0;
    int pos = 0;
    while ( (pos = src.find(s, pos)) != string::npos ){
        ++cnt;
        ++pos;
    }
    return cnt;
}

int main(){
    f[0] = "0"; // f is fibonacci bits 
    f[1] = "1";
    while(cin >> n >> s){
        ++cntans;
        len = s.size();
        while (len > f[maxind - 1].size()){
            ++maxind;
            f[maxind] = f[maxind - 1] + f[maxind - 2];
            ++maxind;
            f[maxind] = f[maxind - 1] + f[maxind - 2];
        }
        first = 0;
        while (len > f[first].size()){
            ans[first] = 0;
            ++first;
        }
        second = first + 1; // First 2 fibos >= len(s)
        ans[first] = cntapp(f[first], s); // Number of s appearances in 
        ans[second] = cntapp(f[second], s); // both of these fibos 
        fsize = f[first].size(); 
        ssize = f[second].size();

        if (len == 1){
            for (int i = second + 1; i <= n; ++i){
                ans[i] = ans[i - 1] + ans[i - 2];
            }
            cout << "Case " << cntans << ": " << ans[n] << endl;
        } else{
            fs = f[first].substr(fsize - len + 1, fsize - 1) + 
                    f[second].substr(0, len - 1); // The middle is f[first] + f[second]
            sf = f[second].substr(ssize - len + 1, ssize - 1) + 
                    f[first].substr(0, len - 1); // The middle is f[second] + f[first]
            int cnt_fs = cntapp(fs, s); // number of s appearances in the middle
            int cnt_sf = cntapp(sf, s);
            for (int i = second + 1; i <= n; ++i){
                if ((i - second) % 2){ // Middle is f[first] + f[second]
                    ans[i] = ans[i - 1] + ans[i - 2] + cnt_sf;
                } else{
                    ans[i] = ans[i - 1] + ans[i - 2] + cnt_fs;
                }
            }
            cout << "Case " << cntans << ": " << ans[n] << endl;
            //cout << ans[first] << ' ' << ans[second];
        }
    }
    
    return 0;
}
    // string s = "a_b_b_c_b";  
    // string a = "_b";
    // cout << cntapp(s, a);