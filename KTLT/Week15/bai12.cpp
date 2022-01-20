#include <bits/stdc++.h>

using namespace std;
int n;
int a[1000002];
long long area;
long long max_area;
int temp;
// 1LL to transfer to long long
int main(){
    ios_base :: sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    max_area = 0;
    stack<int> hist_stack;
    cin >> n;
    for (int i = 0; i < n; ++i){
        cin >> a[i];
        while(!(hist_stack.empty() || a[hist_stack.top()] <= a[i])){
            temp = hist_stack.top();
            hist_stack.pop();
            if (hist_stack.empty()){
                area = 1LL*a[temp] * i;
            }
            else {
                area = 1LL*a[temp] * (i - 1 - hist_stack.top());
            }
            if (area > max_area)
                max_area = area;
        }        
        hist_stack.push(i);      
    }
    while(hist_stack.empty() == 0){
        temp = hist_stack.top();
        hist_stack.pop();
        if (hist_stack.empty()){
            area = 1LL*a[temp] * n;
        }
        else {
            area = 1LL*a[temp] * (n - 1 - hist_stack.top());
        }
        if (area > max_area)
            max_area = area;
    }
    cout << max_area << '\n';
    return 0;
}
