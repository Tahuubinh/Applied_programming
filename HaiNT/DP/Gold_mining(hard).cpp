#include <iostream>
#include <queue>
#include <vector>
using namespace std;

#define maxn 1000005
int n, L1, L2, a[maxn], dp[maxn];
vector<int> b[maxn];

void input(){
    cin >> n >> L1 >> L2;
    for(int i=1; i<=n; i++){
        cin >> a[i];
    }
}
void sol(){
    for(int i=1; i<=L1; i++){
        dp[i] = a[i];
    }

    priority_queue<int> Q;
    Q.push(a[1]);
    for(int i=L1+1; i<=n; i++){
        int t = Q.top();
        dp[i] = t+a[i];
        Q.push(dp[i-L1+1]);
    }
    int ans = 0;
    for(int i=n-L2; i<=n; i++){
        ans = max(ans, dp[i]);
    }
    /*for(int i=1; i<=n; i++){
        cout << dp[i] << endl;
    }*/
    cout << ans;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    input();
    sol();
}

