#include <iostream>
using namespace std;
int n, L1, L2;
long long a[100001];

void input(){
	cin >> n >> L1 >> L2;
	for(int i=0; i<n; i++){
		cin >> a[i];
	}
}

void sol(){
	long long ans = 0;
	long long x[100001] = {0};
	for(int i=0; i<L1; i++){
		x[i] = a[i];
	}

	for(int i=L1; i<n; i++){
		for(int j=i-L2; j<=i-L1; j++){
			if(j>=0){
				x[i] = max(x[i], a[i]+x[j]);
			}
		}
	}
//	for(int i=0; i<n; i++){
//		cout << x[i] << " ";
//	}
//	cout << a[0] << x[0] << endl;
	for(int i = n-L1; i<n; i++){
		ans = max(ans, x[i]);
	}
	cout << ans;
}

int main(){
	input();
	sol();
}

