#include <bits/stdc++.h>
using namespace std;

int t, n;
double avg;
const int MAX = 2e5;
long long a[MAX];

int main(){
    ios_base :: sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    cin >> t;
    while(t--){
        cin >> n;
        long long sum = 0;
        unordered_map<long long, long long> m;
        for (int i = 0; i < n; ++i){
            cin >> a[i];
            ++m[a[i]];
            sum += a[i];
        }
        avg = double(sum) / n;
        double temp = avg * 2;
        long long pair_sum = (long long) temp;
        if (temp != pair_sum){
            cout << 0 << '\n';
            continue;
        }
        long long count = 0;
        for (int i = 0; i < n; ++i){
            count += m[pair_sum - a[i]];
            if (pair_sum - a[i] == a[i]){
                --count;
            }
        }
        cout << count/2 << '\n';
    }


    
    return 0;
}
