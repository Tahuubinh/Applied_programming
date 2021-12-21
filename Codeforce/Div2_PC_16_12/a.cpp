#include <bits/stdc++.h>
using namespace std;
#define endl '\n';
#define pii pair<int, int>
using ll = long long;
using ull = unsigned long long;
int t;

string s, T;

int main(){
    ios_base :: sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> t;
    while(t--){
        cin >> s;
        cin >> T;
        sort(s.begin(), s.end());
        int fa = s.find('a');
        int fb = s.find('b');
        int fc = s.find_last_of('c');
        // cout << fa << fb << fc << endl;
        if (fa == -1 || fb == -1 || fc == -1){
            cout << s << endl;
            continue;
        }
        if (T != "abc"){
            cout << s << endl;
            continue;
        }
        // string sub1 = s.substr(0, fb);
        // string sub = s.substr(fb, fc - 1);
        // if (fc == s.size() - 1){
        //     sub += 'c';
        //     reverse(sub.begin(), sub.end());
        //     string sub3 = s.substr(fc + 1, s.size());
        //     cout << sub1 << ' ' << sub << ' ' << sub3 << endl;
        //     continue;
        // }
        // reverse(sub.begin(), sub.end());
        // string sub3 = s.substr(fc + 1, s.size());
        // cout << sub1 << ' ' << sub << ' ' << sub3 << endl;
        int cb = 0, cc = 0;
        for (int i = fb; i <= fc; ++i){
            if (s[i] == 'c'){
                break;
            }
            ++cb;
        }
        for (int i = fc; i >= fb; --i){
            if (s[i] == 'b'){
                break;
            }
            ++cc;
        }
        for (int i = fb; i < fb + cc; ++i){
            s[i] = 'c';
        }
        for (int i = fb + cc; i <= fc; ++i){
            s[i] = 'b';
        }
        cout << s << endl;
        //cout << cb << ' ' << cc << endl;
    }

    
    return 0;
}
