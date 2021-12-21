#include <bits/stdc++.h>
using namespace std;
#define endl '\n';
#define pii pair<int, int>
using ll = long long;
using ull = unsigned long long;
int t;

const int K = 2e5 + 1;
int w, h, k;
int x[K], y[K];

int main(){
    ios_base :: sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> t;
    while(t--){
        cin >> w >> h;
        cin >> k;
        for (int i = 1; i <= k; ++i){
            cin >> x[i];
        }
        int day1 = x[k] - x[1];
        int min1 = x[1];
        int max1 = x[k];

        cin >> k;
        for (int i = 1; i <= k; ++i){
            cin >> x[i];
        }
        int day2 = x[k] - x[1];
        int min2 = x[1];
        int max2 = x[k];

        cin >> k;
        for (int i = 1; i <= k; ++i){
            cin >> y[i];
        }
        int day3 = y[k] - y[1];
        int min3 = y[1];
        int max3 = y[k];

        cin >> k;
        for (int i = 1; i <= k; ++i){
            cin >> y[i];
        }
        int day4 = y[k] - y[1];
        int min4 = y[1];
        int max4 = y[k];
        
        // ll s1 = 1LL * day1 * max(max3, max4);
        // ll s2 = 2LL * day2 * (h - min(min3, min4));
        // ll s3 = 1LL * day3 * max(max1, max2);
        // ll s4 = 2LL * day4 * (w - min(min1, min2));
        // s1 = max(s1, s2);
        // s2 = max(s3, s4);
        // cout << max(s1, s2) << endl;
        ll s1 = 1LL * max(day1, day2) * h;
        ll s2 = 1LL * max(day3, day4) * w;
        cout << max(s1, s2) << endl;
    }

    
    return 0;
}
