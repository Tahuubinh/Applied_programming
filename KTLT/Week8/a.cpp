#include <bits/stdc++.h>
using namespace std;
#define endl '\n';
#define pii pair<int, int>
using ll = long long;
using ull = unsigned long long;

bool findmax(int a, int b){
    return a > b;
}

bool findmin(int a, int b){
    return a < b;
}

int findOpt(int a[], int n, bool (*compare)(int, int)){
    int opt = a[0];
    for (int i = 1; i < n; ++i){
        if (compare(a[i], opt)){
            opt = a[i];
        }
    }
    return opt;
}

int main(){
    ios_base :: sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int a[] = {2, 1, 5, 4, 3};
    int n = sizeof(a)/sizeof(int);
    cout << "Min: " << findOpt(a, n, findmin) << endl;
    cout << "Max: " << findOpt(a, n, findmax);
    
    return 0;
}
