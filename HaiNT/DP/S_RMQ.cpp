// 5-H.RMQ
#include <iostream>
#include <bits/stdc++.h>
#include <math.h>
using namespace std;
int n, a[1000001] , m, ans = 0;

int M[20][1000001];

void processing(){
	for(int i=0; i<n; i++){
		M[0][i] = a[i];
	}
	for(int j=1; (1 << j)<=n; j++){
		for(int i = 0; ((i+(1<<j))<=n); i++)
			M[j][i] = min(M[j-1][i], M[j-1][i+(1<<(j-1))]);
	}
}

int rmq(int l, int r){
	int x = floor(log(r-l+1) / log(2));
//	cout << x;
	return min(M[x][l], M[x][r-(1<<x)+1]);

}

void input(){
	cin >> n;
	for(int i=0; i<n; i++){
		cin >> a[i] ;
	}
	cin >> m;
	processing();
	while(m--){
		int c, b;
		cin >> c >> b;
		ans += rmq(c, b);
	}
	cout << ans;
//cout << rmq(0, 5);
//cout << floor(log(6)/log(2));
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	input();
//	for(int j=0; j<n; j++){
//		for(int i = 0; i<n; i++){
//			cout << M[j][i] << " ";
//		}
//		cout << endl;
//	}
}

