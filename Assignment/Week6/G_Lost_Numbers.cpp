#include <bits/stdc++.h>
using namespace std;
#define pii pair<int, int>
using ll = long long;
using ull = unsigned long long;

int a[7] = {0, 4, 8, 15, 16, 23, 42};
int t11, t23, t24, t45;
pii ch[5000];
int ans[7];
int check[43];

int main(){
    for (int i = 1; i <= 5; ++i){
        for (int j = i + 1; j <= 6; ++j){
            ch[a[i] * a[j]] = make_pair(a[i], a[j]);
        }
    }
    cout << "? 1 1" << endl;// fflush(stdout);
    cin >> t11;
    cout << "? 2 3" << endl; //fflush(stdout);
    cin >> t23;
    cout << "? 2 4" << endl; //fflush(stdout);
    cin >> t24;
    cout << "? 4 5" << endl;// fflush(stdout);
    cin >> t45;
    ans[1] = sqrt(t11);
    //cout << ans[1];
    //cout << ch[t23].first;
    if(ch[t23].first == ch[t24].first || ch[t23].second == ch[t24].first){
        ans[2] = ch[t24].first;
        ans[3] = t23 / ans[2];
        ans[4] = ch[t24].second;
        //cout << "haha";
    } else{
        ans[2] = ch[t24].second;
        ans[3] = t23 / ans[2];
        ans[4] = ch[t24].first;
        //cout << "haha";
    }
    //cout << ans[2] << ' ' << ans[3] << ' ' << ans[4] << endl;
    ans[5] = t45 / ans[4];
    cout << "! ";
    for (int i = 1; i < 6; ++i){
        cout << ans[i] << ' ';
    }
    check[ans[1]] = check[ans[2]] = check[ans[3]] = check[ans[4]] = check[ans[5]] = 1;
    for (int i = 1; i < 7; ++i){
        if (!check[a[i]]){
            cout << a[i];
            break;
        }
    }
    
    
    return 0;
}
