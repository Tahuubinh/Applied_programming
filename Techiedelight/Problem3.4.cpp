#include <bits/stdc++.h>
using namespace std;
int a[1000], n;
int mem[1000];
// 6 3 4 2 1 5 6
void init(){
    memset(mem, -1, sizeof(mem));
}

//#Quy hoach dong
int lis(int i) {
    if (mem[i] != -1) return mem[i];
    int res = 1;
    for(int j = 0; j < i; j++) {
        if (a[j] < a[i])
            res = max(res, lis(j) + 1);
    }
    mem[i] = res;
    return res;
    /*****************
    # YOUR CODE HERE #
    *****************/
}

//#Truy vet loi giai
void trace(int i){
    for (int j = 0; j < i; j++){
        if (a[j] < a[i] && mem[i] == mem[j] + 1){
            trace(j);
            break;
        }
    }
    cout<<a[i]<<" ";
    /*****************
    # YOUR CODE HERE #
    *****************/
}

int main(){
    init();
    cin >> n;
    for(int i = 0; i < n; i++) cin >> a[i];
    int res = 1, pos = 0;
    for(int i = 1; i < n; i++){
        if (res < lis(i)){
            res = lis(i);
            pos = i;
        }
    }
    cout << res << endl;
    trace(pos);
    return 0;
}
