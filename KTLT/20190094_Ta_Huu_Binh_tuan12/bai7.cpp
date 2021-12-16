#include <bits/stdc++.h>
using namespace std;

struct state{
    int i, j, old_L;
    //# constructor
    state(int _i = 0, int _j = 0, int _L = 0):
        i(_i), j(_j), old_L(_L){}
};

int main() {
    int n, k;
    cin >> n >> k;
    int x[n+1];
    stack<state> s;
    //# number of consecutive suffix 1
    int L = 0;
    s.push(state(1, 0));
    while (!s.empty()){
        state &top = s.top();
        //# if a new binary sequence is found
        if (top.i > n){
            for (int i = 1; i <= n; ++i)
                cout << x[i] << " \n"[i == n];
            s.pop();
            continue;
        }
        
        if (top.j > 1){
            s.pop();
            continue;
        }
        if (top.j){
            L = top.old_L;
            if (L + 1 < k){
                x[top.i] = 1;
                s.push(state(top.i + 1, 0, L + 1));
            }
        }
        else {
            x[top.i] = 0;
            L = 0;
            s.push(state(top.i + 1, 0, 0));
        }
        ++top.j;

    }
    return 0;
}

