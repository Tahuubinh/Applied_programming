#include <iostream>
#include <queue>
#include <climits>
using namespace std;

vector<int> dijkstra(const vector< vector< pair<int, int> > >&adj) {
    int n = adj.size();
    vector<int> D(n);
    vector<int> P(n);
    struct compare{
        bool operator() (pair<int, int> a, pair<int, int> b){
            return a.second > b.second;
        }
    };
    priority_queue<pair<int, int>, vector<pair<int, int>>, compare> q;
    
    for (int i = 0; i < n; ++i){
        D[i] = INT_MAX;
        P[i] = 0;
    }
    D[0] = 0;
    for (int i = 0; i < n; ++i){
        q.push({i, D[i]});
    }

    while (!q.empty()){
        pair<int, int> x = q.top();
        q.pop();
        int ubest = x.first;
        P[ubest] = 1;

        for (pair<int, int> vp: adj[ubest]){
            int v = vp.first;
            if (!P[v]){
                int weight = vp.second;
                if (D[v] > D[ubest] + weight){
                    D[v] = D[ubest] + weight;
                    q.push({v, D[v]});
                }
            }
        }

    }
    return D;
}

int main() {
    int n = 9;
    vector< vector< pair<int, int> > > adj(n);
    auto add_edge = [&adj] (int u, int v, int w) {
        adj[u].push_back({v, w});
        adj[v].push_back({u, w});
    };

    add_edge(0, 1, 4);
    add_edge(0, 7, 8);
    add_edge(1, 7, 11);
    add_edge(1, 2, 8);
    add_edge(2, 3, 7);
    add_edge(2, 8, 2);
    add_edge(3, 4, 9);
    add_edge(3, 5, 14);
    add_edge(4, 5, 10);
    add_edge(5, 6, 2);
    add_edge(6, 7, 1);
    add_edge(6, 8, 6);
    add_edge(7, 8, 7);

    vector<int> distance = dijkstra(adj);
    for (int i = 0; i < distance.size(); ++i) {
        cout << "distance " << 0 << "->" << i << " = " << distance[i] << endl;
    }

    return 0;
}