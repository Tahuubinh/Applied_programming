#include<stdio.h>
int a[200010],b[200010],ta[200010],tb[200010];
int main(){
	int t;
	for(scanf("%d",&t);t;--t){
		int n;
		scanf("%d",&n);
		for(int i=1;i<=n;++i)
			ta[i]=tb[i]=0;
		for(int i=1;i<=n;++i)
			scanf("%d%d",&a[i],&b[i]),
			++ta[a[i]],++tb[b[i]];
		long long ans=1ll*n*(n-1)*(n-2)/6;
		for(int i=1;i<=n;++i)
			ans-=1ll*(ta[a[i]]-1)*(tb[b[i]]-1);
		printf("%lld\n",ans);
	}
	return 0;
} 