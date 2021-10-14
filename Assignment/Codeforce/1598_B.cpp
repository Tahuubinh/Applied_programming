#include<bits/stdc++.h>
using namespace std;
int t,n;
bitset<1005> a[6];
int main()
{
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d",&n);
		for(int i=1;i<=5;++i)
            a[i]=0;
		for(int i=1,x;i<=n;++i)
		    for(int j=1;j<=5;++j){
                scanf("%d",&x);
                a[j][i]=x;
            }
		bool flag=0;
		for(int i=1;i<=5;++i)
            for(int j=i+1;j<=5;++j){
                if(a[i].count() >= n/2 && a[j].count() >= n/2 &&
                (a[i]|a[j]).count()>=n)
                    flag=1;
            }
		
		printf(flag?"YES\n":"NO\n");
	}
	return 0;
}