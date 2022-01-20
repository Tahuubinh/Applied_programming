#include <bits/stdc++.h>
using namespace std;
#define endl '\n';
#define pii pair<int, int>
#define fr(i,x,y) for(int i = x; i <= y; ++i)
using ll = long long;
using ull = unsigned long long;
int n,res=1;
vector<pii>s;

bool compare(pii s1, pii s2){
	return s1.second<s2.second;
}

int main(){
    ios_base :: sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> n;
	int a,b;
	fr(i, 1, n){
		cin>>a>>b;
		s.push_back({a,b});
	}	
	sort(s.begin(),s.end(),compare);
	int right=s[0].second;
	fr(i, 1, n - 1){
		if (s[i].first>right){
			right=s[i].second;
			res++;
		}
	}
	cout << res;
}