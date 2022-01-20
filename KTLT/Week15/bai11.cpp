#include <bits/stdc++.h>
using namespace std;
#define endl '\n';
#define fr(i,x,y) for(int i = x; i <= y; ++i)
using ll = long long;

const int N = 100001;
ll n, s, cnt, total;
ll a, k;

struct compair{
    bool operator()(pair<ll, ll> a, pair<ll, ll> b){
        int tempa, tempb;

        if (a.first > a.second){
            tempa = a.second;
        } else {
            tempa = a.first;
        }

        if (b.first > b.second){
            tempb = b.second;
        } else {
            tempb = b.first;
        }

        return tempa < tempb;
    }
};

priority_queue<pair<ll, ll>, vector<pair<ll, ll>>, compair> pq;

int main(){
    ios_base :: sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> n;
    cin >> s;
    fr(i, 1, n){
        cin >> a;
        total += a;
        cin >> k;
        pq.push(make_pair(a, k));
    }

    while (s && !pq.empty()){
        pair<ll, ll> maxkill = pq.top();
        pq.pop();
        a = maxkill.first;
        k = maxkill.second;
        if (a <= k){
            cnt += a;
        } else {
            cnt += k;
            pq.push(make_pair(a - k, k));
        }
        --s;
    }
    cout << total - cnt;
    
    
    
    
    return 0;
}
