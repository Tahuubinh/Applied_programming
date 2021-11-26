#include <bits/stdc++.h>
using namespace std;
#define endl '\n';
#define pii pair<int, int>
#define pdd pair<double, double>
#define X first
#define Y second
using ll = long long;
using ull = unsigned long long;

int n;
const int M = 5e4 + 1;
pdd point[M];
set<pdd> s;

double euclid(pdd a, pdd b){
    return sqrt((a.X-b.X)*(a.X-b.X)+(a.Y-b.Y)*(a.Y-b.Y));
}

bool cprX(pdd a, pdd b)
{
    if(a.X < b.X) return true;
    if(a.X == b.X)
    {
        if(a.Y <= b.Y) return true;
    }
    return false;
}

int main(){
    ios_base :: sync_with_stdio(0); cin.tie(0); cout.tie(0);
    
    cin >> n;
    for (int i = 1; i <= n; ++i){
        cin >> point[i].X >> point[i].Y;
    }
    sort (point + 1, point + n + 1, cprX);
    double minD = euclid(point[1], point[2]);
    int j = 1;
    for (int i = 1; i <= n; ++i){
        while(point[i].X - point[i].X > minD){
            s.erase(pdd(point[j].Y, j));
            ++j;
        }
        set<pdd>::iterator it = s.upper_bound(pdd(point[i].Y+minD,0));
        set<pdd>::iterator _it = s.lower_bound(pdd(point[i].Y-minD,0));
    }
    
    
    return 0;
}







