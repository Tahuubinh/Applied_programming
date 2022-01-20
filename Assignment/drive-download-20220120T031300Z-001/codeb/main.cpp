#include<bits/stdc++.h>
#define fi  first
#define se  second
#define int long long
#define ii  pair<int,int>
#define iii pair<int,ii>
#define pb push_back
#define endl "\n"
#define debug(x) cerr<<#x<<'='<<(x)<<endl;
#define debugp(x) cerr<<#x<<"= {"<<(x.first)<<", "<<(x.second)<<"}"<<endl;
#define debug2(x, y) cerr<<"{"<<#x<<", "<<#y<<"} = {"<<(x)<<", "<<(y)<<"}"<<endl;
#define debugv(v) {cerr<<#v<<" : ";for (auto x:v) cerr<<x<<' ';cerr<<endl;}
using namespace std;
//  sort(v.begin(), v.end(), greater<int>());
void invector( vector< int > p ){
    cout<<" in p : ";
    for(auto x : p ){
        cout<<x<<" ";
    }
    cout<<endl;
}
/*
const int mod = 1e9 + 7 ;
const int N = 1e5 + 10  ;
int fac[N];
int inv[N];
int power1( int a , int  b){
    if( b == 0  ) return 1 ;
    int c=  b /2 ;
    c = power1( a , c ) % mod ;
    c = ( c * c ) % mod   ;
    if( b % 2 == 1 ) c = (  c  * a )%mod;
    return c ;
}
void init(int n){
	fac[0]=1;
	for(int i=1;i<=n;++i)
		fac[i]=1ll*fac[i-1]*i%mod;
	inv[n]=power1(fac[n],mod-2);
	for(int i=n-1;i>=0;--i)
		inv[i]=1ll*inv[i+1]*(i+1)%mod;
} */
int gcd(int a,int b)
{
	if (b==0) return a;
	return gcd(b,a%b);
}
const int N = 2e5 + 10 ;
vector< ii > ds[ N ] ;
int ans = -1e18 ;
int dfs( int id , int rid ){
    int max1 = -1e18 ;
    int max2 = -1e18 ;
    for(auto [x,w ] : ds[id] ){
        if( x == rid ) continue ;
        int s = dfs( x , id ) + w ;
        if( max1 <= s ){
            max2 = max1 ;
            max1 = s ;
        }
        else if( max2 < s ){
            max2 = s ;
        }
    }
    if( max1 == -1e18  ) return 0 ;
    else if( max2 == -1 ){
            // thêm so với code cũ
        ans = max( ans , max1 ) ;
        return max1 ;
    }
    else{
        ans = max( ans , max1 + max2 ) ;
     // thêm so với code cũ
        if( max2 < 0 ){
            ans = max( ans, max1 ) ;
        }
        return max1 ;
    }
}
signed main(){
        srand(time(NULL));ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int n ; cin>> n ;
    for(int i = 0 ; i < n - 1 ; i++){
        int u , v , w ;cin>> u>> v >> w ;
        ds[ u ].pb( ii( v, w ) ) ;
        ds[ v ].pb( ii( u, w ) ) ;
    }
    int h = dfs( 1 , -1 ) ;
    ans =max( ans , h ) ;
    cout<<ans<<endl;
}
