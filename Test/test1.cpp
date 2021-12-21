#include <bits/stdc++.h>
using namespace std;
 
bool f() {
	int n;
	cin >> n;
	vector<pair<char, int> > a(n);
	for(int i = 0; i<n; i++) cin >> a[i].second;
	string s;
	cin >> s;
	for(int i = 0; i<n; i++) a[i].first = s[i];
	sort(a.begin(), a.end());
	for(int i = 0; i<n; i++) {
		if(a[i].second<i+1 && a[i].first == 'B') return false;
		if(a[i].second>i+1 && a[i].first == 'R') return false;
	}
	return true;
} 
 
int main() {
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	// int t;
	// cin >> t;
	// while (t--) {
	// 	//slv();
	// 	cout << (f()?"YES":"NO") << '\n';
	// }
  int n = 10;
  vector<int> a(n);
  a[0] = 8;
  cout << a[0];
	return 0;
}