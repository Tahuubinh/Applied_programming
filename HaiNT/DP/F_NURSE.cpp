//U-NURSE
#include <iostream>
using namespace std;
long long a[10000], n, k1, k2, ans = 0;

void TRY(int k){
	for(int i=k1; i<=k2; i++){
		k+=i;
		if(k==n || k == (n-1)){
			ans ++;
		}
		else{
			if(k+k1 <= n) TRY(k+1);
		}
		k-=i;
	}
}

int main(){
	cin >> n >> k1 >> k2;
	TRY(0);
	TRY(1);
	cout << ans;
}

