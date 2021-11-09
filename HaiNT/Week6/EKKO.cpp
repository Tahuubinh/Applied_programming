#include <bits/stdc++.h>
using namespace std;
#define HNT ios_base::sync_with_stdio(false); cin.tie();

#define ll long long
#define pii pair <int, int>
#define pb push_back
#define mp make_pair

#define mod 1000000009
long long woodCut(vector<long long> &v , long long h){
    long long sum = 0;
    for(int i = 0 ; i < v.size() ; i++){
        if(v[i] > h)
            sum += v[i] - h;
    }
    return sum;
}

long long binarysearch(vector<long long> &v , long long required){
    long long low = 0 , mid , high = LLONG_MAX/10;
    long long ans = LLONG_MIN;
    while(low < high){
        mid = (low + high) >> 1;
        long long wood = woodCut(v, mid);
        if(wood >= required){
            low = mid+1;
            ans = max(ans, mid);
        }
        else
            high = mid;
    }
    return ans;
}
int main(){
    HNT;
    long long n , m;
    cin >> n >> m;
    vector<long long> v(n);
    for(int i = 0; i < n; i++){
        cin >>v[i];
    }
    cout<< binarysearch( v, m);
    return 0;
}
