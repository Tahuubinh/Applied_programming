#include <bits/stdc++.h>
using namespace std;
#define endl '\n';
#define pii pair<int, int>
using ll = long long;
using ull = unsigned long long;
int t;

const double PI = atan(1)*4;
int n, f;
int temp;
double s[10001];
double smax;

int main(){
    ios_base :: sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> t;
    cout << fixed << setprecision(6);
    while(t--){
        cin >> n >> f;
        smax = 0;
        for (int i = 1; i <= n; ++i){
            cin >> temp;
            s[i] = temp * temp * PI;
            if (s[i] > smax){
                smax = s[i];
            }
        }
        double left = 0;
        double right = smax;
        double mid;
        int sum;
        while (right - left > 1e-7){
            mid = (left + right) / 2;
            sum = 0;
            for (int i = 1; i <= n; ++i){
                sum += floor(s[i] / mid);
            }
            if (sum > f){
                left = mid;
            }  else {
                right = mid;
            }
        }
        cout << mid << endl;
    }

    
    return 0;
}
