#include <bits/stdc++.h>
using namespace std;
#define endl '\n';
#define pii pair<int, int>
using ll = long long;
using ull = unsigned long long;
int t;

const int M = 1e5 + 1;
int n;
int a[M], b[M];
// pii win1[M];
int win[M];
vector<int> v1, v2;

int main(){
    ios_base :: sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> t;
    while(t--){
        cin >> n;
        memset(win, 0, sizeof(win));
        for (int i = 0; i < n; ++i){
            cin >> a[i];
        }
        for (int i = 0; i < n; ++i){
            cin >> b[i];
        }
        int max1 = *max_element(a, a + n);
        //cout << max1 << endl;
        for (int i = 0; i < n; ++i){
            if (a[i] == max1){
                max1 = i;
                break;
            }
        }
        int max2 = *max_element(b, b + n);
        for (int i = 0; i < n; ++i){
            if (b[i] == max2){
                max2 = i;
                break;
            }
        }
        int c1 = b[max1];
        int c2 = a[max2];
        win[max1] = win[max2] = 1;
        //cout << max1 << max2 << c1 << c2 << endl;
        int temp = INT_MAX;
        for (int i = 0; i < n; ++i){
            if (i != max1){
                if (b[i] >= c1){
                    win[i] = 1;
                    temp = min(temp, win[i]);
                }
            }
        }
        for (int i = 0; i < n; ++i){
            if (i != max1){
                if (a[i] >= temp){
                    win[i] = 1;
                }
            }
        }

        for (int i = 0; i<n; ++i){
            cout << win[i];
        }
        cout << endl;

        
    }

    
    return 0;
}
