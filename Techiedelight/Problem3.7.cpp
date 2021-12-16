#include <bits/stdc++.h>
using namespace std;
/* Concursive
int n, k, x[100], L;
void duyet(int i){
    if ( i > n) {
        for (i = 1; i <= n; i++)
            cout << x[i]<<" ";
            cout << endl;
        return;
    }
    for (int j = 0; j <= 1; ++j) {
        int old_L;
        if (j == 0 || L + 1 < k) {
            x[i] = j;
            old_L = L;
            L = j ? L + 1 : 0;
            duyet(i + 1);
            L = old_L;
        }
    }
}

int main() {
    cin >> n >> k;
    duyet(1);
    return 0;
}
*/
struct state{
    int i, j, old_L;
    //# constructor
    state(int _i = 0, int _j = 0):
        i(_i), j(_j){}
};

int main() {
    int n, k;
    cin >> n >> k;
    int x[n+1];
    stack<state> s;
    //# number of consecutive suffix 1
    int L = 0;
    s.push(state(1,0));
    while (!s.empty()){
        state &top = s.top();
        //# if a new binary sequence is found
        if (top.i > n){
            for (int i = 1; i <= n; ++i)
                cout << x[i] <<" ";
                cout << endl;
            s.pop();
            continue;
        }
        // #backtrack
        if (top.j > 0)
            L = top.old_L;

        // #every subtree are visited
        if (top.j > 1) {
            s.pop();
            continue;
        }

        if ((L + 1) < k || top.j == 0) {
            x[top.i] = top.j;
            top.old_L = L;
            L = (top.j) ? (L + 1) : 0;
            s.push(state(top.i + 1,0));
        }
        ++top.j;
        //# Khử đệ quy
        /*****************
        # YOUR CODE HERE #
        *****************/
    }
    return 0;
}
