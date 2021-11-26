//5-J.Warehouse
#include <iostream>
using namespace std;
int N, T, D;
int a[1005], t[1005], res[1005][1005] = {0};

void input(){
	cin >> N >> T >> D;
	for(int i=1; i<=N; i++){
		cin >> a[i];
	}
	for(int i=1; i<=N; i++){
		cin >> t[i];
	}
}

void sol(){
	for(int i=1; i<=N; i++){
		for(int k=1; k<=T; k++){
			res[i][k] = a[i];
			if(k<t[i]){
				res[i][k] = 0;
				continue;
			}
			if(i>=D)
			{
				int tmp = 0;
				for(int j=i-D; j<i; j++){
					tmp = max(res[j][k-t[i]] + a[i], tmp);
					res[i][k] = tmp;
				}
			}
// 			cout << res[i][k] << endl;
		}
	}
	int ans = 0;
	for(int i=1; i<=N; i++){
		for(int j=1; j<=T; j++){
			ans = max(ans, res[i][j]);
		}
// 		cout << ans << endl;
	}
	cout << ans;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	input();
	sol();
}
