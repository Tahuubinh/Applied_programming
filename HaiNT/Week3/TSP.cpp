#include <bits/stdc++.h>
using namespace std;

const int N = 21;
const int M = 401;
int n,m, mt[N][N];
int x[N], xopt[N], fk, fopt, cmin = 1000001;

bool visit[N];

void init(){
    x[1] = 1;
    visit[1] = true;
    fk = 0;
    fopt = INT_MAX;
}

void solution() {
    for (int i = 1; i <= n; i++ )
        cout<<xopt[i]<<"->";
        cout<<xopt[1];
        cout<<endl;
        cout<<"minimum cost: "<<fopt;
}

void TRY ( int k ){
    for ( int y = 2; y <= n; y ++) {
        if((k == n) && !mt[y][1]) continue;
        if(!mt[x[k-1]][y]) continue;
        if ( !visit[y] ){
            x[k] = y;
            visit[y] = true;
            fk += mt[x[k-1]][y];
            if( k == n){
                if (fk + mt[x[n]][1] < fopt ){
                    fopt = fk + mt[x[n]][1];
                    /*for( int i = 1; i <= n; i++)
                        xopt[i] = x[i];*/
                }
            }else
            if (fk + cmin * (n - k + 1) < fopt ) TRY(k + 1);
            visit[y] = false;
            fk -= mt[x[k-1]][y];
        }
    }
}

int main() {
    for ( int i = 1 ; i <= n; i++)
    for ( int j = 1 ; j <= n; j++){
        mt[i][j] = 0;
    }

    cin >> n >> m;

    while (m--){
        int i,j;
        cin>>i>>j>>mt[i][j];
    }

    for ( int i = 1 ; i <= n; i++)
    for ( int j = 1 ; j <= n; j++){
        if (mt[i][j] != 0)
            cmin = (cmin > mt[i][j])? mt[i][j]:cmin;
    }
    init();
    for (int i = 2;i <= n;i++) visit[i] = false;
    TRY(2);
    cout<< fopt;
    return 0;
}

