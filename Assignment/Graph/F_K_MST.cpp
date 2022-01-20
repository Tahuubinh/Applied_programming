#include <bits/stdc++.h>
using namespace std;
#define endl '\n';
#define fr(i,x,y) for(int i = x; i <= y; ++i)
#define pii pair<int, int>
using ll = long long;
using ull = unsigned long long;

const int N = 21;
int n, m, k, u, v, w;
int edge[N][N], visited[N], x[N];
int min_weight = INT_MAX;
int cmin = INT_MAX;
int total;

int p[N];

struct Edge{
    int u;
    int v;
    int w;
    Edge(int ui = 0, int vi = 0, int wi = 0){
        u = ui;
        v = vi;
        w = wi;
    }
};

vector<Edge> edges;

int find(int x){
    if (p[x] == x){
        return x;
    } else {
        p[x] = find(p[x]);
        return p[x];
    }
}

void unite(int u, int v){
    p[find(u)] = find(v);
}

void reset(){    
    fr(i, 1, n){
        p[i] = i;
    }
}

bool check(int btr, int i){
    if (visited[i]){
        return false;
    }
    if (i > (m - k) + btr){
        return false;
    }
    reset();
    for (int j = 1; j < btr; ++j){
        unite(edges[x[j]].u, edges[x[j]].v);
    }

    int pu = find(edges[i].u);
    int pv = find(edges[i].v);
    if (pu == pv){
        return false;
    }

    return true;
}

void Try(int btr){
    fr(i, 1, m){
        if (check(btr, i)){
            visited[i] = true;
            x[btr] = i;
            total += edges[x[btr]].w;
            if (btr == k){
                min_weight = min(min_weight, total);
            } else {
                if (total + (k - btr) * cmin < min_weight){
                    Try(btr + 1);
                }
            }
            visited[i] = false;
            total -= edges[x[btr]].w;
        }
    }
}

int main(){
    ios_base :: sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> n >> m >> k;
    edges.resize(m + 1);
    fr(i, 1, m){
        cin >> u >> v >> w;
        edges[i] = Edge(u, v, w);
        int cmin = min(cmin, w);
    }
    
    Try(1);

    cout << min_weight;

    return 0;
}
