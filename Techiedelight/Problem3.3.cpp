#include <bits/stdc++.h>
using namespace std;

int n, c[100][100];
int x[100], xopt[100], fk, fopt, cmin = 1000;

void init(){
    x[1] = 1;
    fk = 0;
    fopt = INT_MAX;
}

void print() {
    for (int i = 1; i <= n; i++ )
        cout<<xopt[i]<<"->";
        cout<<xopt[1];
        cout<<endl;
        cout<<"minimum cost: "<<fopt;
}
int visit( int y, int k ){
    for ( int i = 2; i < k ; i++)
        if ( y == x[i] ) return 0;
    return 1;
}

void process ( int k ){
    for ( int y = 2; y <= n; y ++)
    if ( visit (y,k) ){
        x[k] = y;
        fk += c[x[k-1]][y];
        if( k == n){
            if (fk + c[x[n]][1] < fopt ){
                fopt = fk + c[x[n]][1];
                for( int i = 1; i <= k; i++)
                    xopt[i] = x[i];
            }
        }else
        if (fk + cmin * (n - k + 1) < fopt ) process(k + 1);
        fk -= c[x[k-1]][y];
    }
}

int main() {
    cin >> n;
    for ( int i = 1 ; i <= n; i++)
    for ( int j = 1 ; j <= n; j++){
        cin>>c[i][j];
        if (c[i][j] != 0)
        cmin = (cmin > c[i][j])? c[i][j]:cmin;
    }
    init();
    process(2);
    print();
    return 0;
}
