#include <bits/stdc++.h>
using namespace std;

int main() {
    string s, t;
    int k, n;
    cin >> k;
    while (k--)
    cin >> n >> s >> t,
    cout << ( (bitset<100>(s) & bitset<100>(t) ).count() ? "NO\n" : "YES\n");
}

// #include<bits/stdc++.h>
// using namespace std;
// int t,n;
// string s[2];
// bool r;
// int main(){
// 	cin>>t;
// 	while(t--){
// 		cin>>n>>s[0]>>s[1];
// 		r=1;
// 		for(int i=1;i<n;i++)r&=(s[0][i]=='0'||s[1][i]=='0');
// 		puts(r?"YES":"NO");
// 	}
// }