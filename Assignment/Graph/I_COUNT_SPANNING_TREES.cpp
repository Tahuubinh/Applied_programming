#include <bits/stdc++.h>
using namespace std;
#define endl '\n';
#define pii pair<int, int>
#define fr(i,x,y) for(int i = x; i <= y; ++i)
using ll = long long;
using ull = unsigned long long;

int m, n, u, v;
int a[26];
ll cnt;
int visited[26];
int p[21];
int r[21]; // rank
int x[30];

struct Edge{
    int u, v;
    Edge(int _u = 0, int _v = 0){
        u = _u;
        v = _v;
    }
};

vector<Edge> edges;

// struct UF {
//     vector<int> parents;

//     int find(int x){
//         if (parents[x] == x){
//             return x;
//         } else {
//             parents[x] = find(parents[x]);
//             return parents[x];
//         }
//     }

//     void unite(int x, int y){
//         parents[find(x)] = find(y);
//     }
// };

// UF uf;

void makeSet(int x){
    p[x] = x;
    r[x] = 0;
}

void unionSet(int x, int y){
    if (r[x] > r[y]){
        p[y] = x;
    } else {
        p[x] = y;
        if (r[x] == r[y]){
            ++r[y];
        }
    }
}

int findSet(int x){
    while (p[x] != x){
        x = p[x];
    }
    return p[x];
}

bool check(int a, int i){
    if (visited[i]){
        return false;
    }
    if (a > 1){
        if (x[a - 1] > i){
            return false;
        }
        else if (i > m - n + a + 1){
            return false;
        }
    } else if (i > m - n + 2){
        return false;
    }
    for (int j = 1; j <= n; ++j){
        makeSet(j);
    }

    for (int j = 1; j < a; ++j){
        int pfirst = findSet(edges[x[j]].u);
        int psecond = findSet(edges[x[j]].v);
        unionSet(pfirst, psecond);
    }

    int pfirst = findSet(edges[i].u);
    int psecond = findSet(edges[i].v);

    if (pfirst == psecond){
        return false;
    }

    return true;
}

void Try(int btr){
    fr(i, 1, m){
        if (check(btr, i)){
            visited[i] = true;
            x[btr] = i;
            if (btr == n - 1){
                ++cnt;
            } else {
                Try(btr + 1);
            }
            visited[i] = false;
        }
    }
}

int main(){
    ios_base :: sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> n >> m;
    edges.resize(m + 1);
    a[0] = 0;
    for (int i = 1; i <= m; ++i){
        cin >> u >> v;
        edges[i] = Edge(u, v);
    }
    Try(1);
    cout << cnt;
    
    return 0;
}
