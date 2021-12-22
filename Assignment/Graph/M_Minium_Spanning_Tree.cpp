#include <bits/stdc++.h>
using namespace std;
#define endl '\n';
#define pii pair<int, int>
using ll = long long;
using ull = unsigned long long;

int n, m, u, v, w;

struct Edge {
    int u, v;
    int w;
    Edge(int _u = 0, int _v = 0, int _w = 0){
        u = _u;
        v = _v;
        w = _w;
    }
};

struct UF{
    vector<int> parents;
    UF(int n){
        parents.resize(n + 1, 1);
    }

    int find(int x){
        if (parents[x] == x){
            return x;
        } else {
            parents[x] = find(parents[x]);
            return parents[x];
        }
    }

    void unite(int x, int y){
        parents[find(x)] = find(y);
    }
};

const int M = 1e5 + 1;
const int N = 1e5 + 1;
vector<Edge> edges;

bool compare (const Edge &a, const Edge &b){
    return a.w < b.w;
}

vector<Edge> mst (int n, vector<Edge> edges){
    UF uf(n);
    sort(edges.begin(), edges.end(), compare);
    vector<Edge> res;
    for (Edge e: edges){
        int u = e.u;
        int v = e.v;
        if (uf.find(u) != uf.find(v)){
            uf.unite(u, v);
            res.push_back(e);
        }
    }
    for (Edge e: res){
        cout << e.u << ' ' << e.v << ' ' << e.w << endl;
    }
    return res;
}

int main(){
    ios_base :: sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> n >> m;
    for (int i = 1; i <= m; ++i){
        cin >> u >> v >> w;
        edges.push_back(Edge(u, v, w));
    }
    // for (Edge e: edges){
    //     cout << e.u << ' ' << e.v << ' ' << e.w << endl;
    // }


    vector<Edge> ans = mst(n, edges);
    int res = 0;
    for (Edge e: ans){
        cout << e.u << ' ' << e.v << ' ' << e.w << endl;
        res += e.w;
    }
    cout << res;
    
    
    return 0;
}
