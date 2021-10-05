#include <bits/stdc++.h>
// I solved this problem before: https://github.com/Tahuubinh/Homework/blob/main/Homework/MaxSub.cpp
// Using dynamic programming
using namespace std;

int a[1000001];
long long sum[1000001];
bool check[1000001];
long long max_sum = LLONG_MIN;

long long maxSum(int a[], int n){
    if (n == 0){
        check[0] = true;
        return a[0];
    }
    if (check[n] == true){
        return sum[n];
    }
    check[n] = true;
    sum[n] = max<long long>(maxSum(a, n - 1) + a[n], a[n]);
    return sum[n];

}

int main(){
    int n;
    cin >> n;
    for (int i = 0; i < n; ++i){
        cin >> a[i]; 
    }
    for (int i = 0; i < n; ++i){
        max_sum = max<long long>(maxSum(a, i), max_sum);
    }
    cout << max_sum;

    return 0;
}
