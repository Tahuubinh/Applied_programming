#include <iostream>
#include <algorithm>

using namespace std;
int n, s[2000001], t[2000001], max_l[2000001] = {0};

void input(){
	cin >> n;
	for(int i = 0; i<n; i++){
		cin >> s[i] >> t[i];
	}
}

void sol(){
	int tmp = -1;
	for(int i = 0; i < n; i++){
		max_l[t[i]] = max(max_l[t[i]], t[i] - s[i]);
	}
	int m = *max_element(s, s+n);
	for(int i = 1; i <= m; i++){
		max_l[i] = max(max_l[i-1], max_l[i]);
	}
	int ans = -1;
	for(int i = 0; i < n; i++){
		ans = max(ans, max_l[s[i]-1] + t[i] - s[i]);
	}
	cout << ans;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	input();
	sol();
}
