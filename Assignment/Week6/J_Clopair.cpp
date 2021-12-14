#include <bits/stdc++.h>
using namespace std;
#define endl '\n';
#define pii pair<int, int>
#define pdd pair<double, double>
#define pddi pair<pdd, int>
#define x first.first
#define y first.second
#define id second
using ll = long long;
using ull = unsigned long long;

int n;
const int M = 5e4 + 1;
const double oo = 1e12;
double global_res = oo;
pddi p[M];
int p1, p2;
set<pdd> s;

bool cprX(pddi a, pddi b){
    if(a.x < b.x) return true;
    if(a.x == b.x)
    {
        if(a.y <= b.y) return true;
    }
    return false;
}
bool cprY(pddi a, pddi b){
    if(a.y < b.y) return true;
    if(a.y == b.y)
    {
        if(a.x <= b.x) return true;
    }
    return false;
}

double dis(pddi a, pddi b)
{
    return sqrt((a.x-b.x)*(a.x-b.x)+(a.y-b.y)*(a.y-b.y));
}

double find_min_dis(int l, int r){
    if (l >= r){
        return oo;
    } else if (l+1 == r){
        if (global_res > dis(p[l], p[r])){
            global_res = dis(p[l], p[r]);
            p1 = min(p[l].id, p[r].id);
            p2 = max(p[l].id, p[r].id);
        }
        return dis(p[l], p[r]);
    }

    int mid = (l + r)>>1;
    double D1 = find_min_dis(l, mid);
    double D2 = find_min_dis(mid, r);
    double D = min(D1, D2);
    vector<pddi> X;

    for (int i = l; i <= r; ++i){
        X.push_back(p[i]);
    }
    sort(X.begin(), X.end(), cprY);

    double temp = D;
    for (int i = 0; i < X.size(); ++i){
        for (int j = i + 1; j < X.size(); ++j){
            if (X[i].y + D < X[j].y){
                break;
            }
            if (dis(X[i], X[j]) < global_res){
                p1 = min(X[i].id, X[j].id);
                p2 = max(X[i].id, X[j].id);
                global_res = dis(X[i], X[j]);
            }
            if (dis(X[i], X[j]) < temp){
                temp = dis(X[i], X[j]);
            }
        }
    }
    return temp;
}

int main(){
    ios_base :: sync_with_stdio(0); cin.tie(0); cout.tie(0);
    
    cin >> n;
    for (int i = 1; i <= n; ++i){
        cin >> p[i].x >> p[i].y;
        p[i].id = i;
    }
    sort(p + 1, p + n + 1);
    double res = find_min_dis(1, n);
    
    //cout << p1 << ' ' << p2 << ' ';
    printf("%d %d %0.6lf", p1 - 1, p2 - 1, res);
    
    return 0;
}







