#include<bits/stdc++.h>
using namespace std;
const int N=1e6+1;
int n,m,t,k,mn,a[N],b[N],p[N],ans[N];
bool cmp(int x, int y){
    return a[x] < a[y];
}
int main(){
	cin>>t;
	while(t--){
		cin>>n;
		memset(ans,0,sizeof ans);
		for(int i=1;i<=n;i++) cin>>a[i];
		for(int i=1;i<=n;i++) cin>>b[i],p[i]=i;
		sort(p+1,p+n+1,cmp);
		mn=b[p[n]],ans[p[n]]=1;
		for(int i=n-1;i>=1;i--){
			if(b[p[i]]>mn){
				int res=INT_MAX;
				ans[p[i]]=1;
				for(int j=i+1; j<=n && !ans[p[j]]; j++) ans[p[j]]=1,res=min(res,b[p[j]]);
				mn=min(mn,res);
			}
		}
		for(int i=1;i<=n;i++) cout<<ans[i];
		cout<<endl;
	}
} 