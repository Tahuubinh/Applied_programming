#include <iostream>
#define maxn 105
#define maxm 505
using namespace std;
typedef long long ll;
const int MOD = 1e9 + 7;
ll a[maxn];
int n, m;
ll dp[maxn][maxm] = {0};

void input(){
	cin >> n >> m;
	for(int i=1; i<=n; i++){
		cin >> a[i];
	}

}

void sol(){
	for(int i=1; i<=m/a[1]; i++){
		dp[1][i*a[1]] ++;
		dp[1][i*a[1]] %= MOD;
	}
	for(int i=2; i<=n; i++){
		for(int j=1; j<=m; j++){
			for(int k=1; k<=j/a[i]; k++){
				dp[i][j]+=dp[i-1][j-k*a[i]];
				dp[i][j] %= MOD;
			}
		}
	}
	cout << dp[n][m];
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	input();
	sol();
}
