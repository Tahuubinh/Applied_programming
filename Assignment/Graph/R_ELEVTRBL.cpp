#include <bits/stdc++.h>
using namespace std;
#define endl '\n';
#define pii pair<int, int>
using ll = long long;
using ull = unsigned long long;

int f, s, g, u, d;
const int M = 1e6 + 1;
bool visited[M];

struct Node {
    int time;
    int pos;
    Node (int _time = 0, int _pos = 0){
        time = _time;
        pos = _pos;
    }
};

int bfs(int s){
    Node node = Node (0, s);
    queue<Node> q;
    q.push(node);
    while(!q.empty()){
        Node node = q.front();
        q.pop();
        int time = node.time + 1;
        
        int pos = node.pos + u;
        if (pos == g){
            return time;
        }
        if (!visited[pos] && pos <= f){
            visited[pos] = 1;
            q.push(Node(time, pos));
        }

        pos = node.pos - d;
        if (pos == g){
            return time;
        }
        if (!visited[pos] && pos > 0){
            visited[pos] = 1;
            q.push(Node(time, pos));
        }
    }
    return 0;
}

int main(){
    ios_base :: sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> f >> s >> g >> u >> d;
    int gcd = __gcd(u, d);
    int distance = g - s;
    if (distance % gcd){
        cout << "use the stairs";
        return 0;
    }
    int ans = bfs(s);
    if (ans){
        cout << ans;
    } else {
        cout << "use the stairs";
    }

    
    return 0;
}
