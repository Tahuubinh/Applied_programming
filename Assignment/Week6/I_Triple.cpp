#include <bits/stdc++.h>
using namespace std;
#define endl '\n';
#define pii pair<int, int>
using ll = long long;
using ull = unsigned long long;

int n, k, ans, l, r, temp, mid;
int a[5001];

int count(int left, int right, int key){
    if (left <= right){
        int mid = (left + right) >> 1;
        if (a[mid] == key){
            return 1 + count(left, mid - 1, key)+
                    count(mid + 1, right, key);
        } else if (a[mid] > key){
            return count (left, mid - 1, key);
        } else{
            return count(mid + 1, right, key);
        }
    }
    return 0;
}

int main(){
    ios_base :: sync_with_stdio(0); cin.tie(0); cout.tie(0);
    
    cin >> n >> k;
    for (int i = 1; i <= n; ++i){
        cin >> a[i];
    }
    sort (a + 1, a + 1 + n);
    for (int i = 1; i < n - 1; ++i){
        for (int j = i + 1; j < n; ++j){
            int key = k - a[i] - a[j];
            if (key <= 0){
                break;
            }
            ans += count(j + 1, n, key);
        }
    }
    cout << ans;
    
    return 0;
}
