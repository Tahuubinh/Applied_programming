#include <bits/stdc++.h>
using namespace std;

const int MAX = 1e4;
int n, k;
int il = 0, ir = 0; // len of l and r
pair<int, int> cus[MAX], l[MAX], r[MAX];
long long res;

long long PMcost(pair<int, int> plist[], int len){
    long long cost = 0;
    int bag = 0; // save the number of package being brought
    while (len--){
        int dist = plist[len].first;
        int weight = plist[len].second;
        //cout << len << ' ' << bag << ' ' << weight << ", ";
        // Return to base doesn't cost more
        if (bag >= weight){
            bag -= weight;
            continue;
        }
        weight -= bag;
        //cout << weight << dist;
        int times = (weight - 1)/k + 1;
        bag = times * k - weight; // remainder in bag
        cost += 2ll * times * dist;
    }


    return cost;
}

int main(){
    ios_base :: sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    
    cin >> n >> k;
    for (int i = 0; i < n; ++i){
        cin >> cus[i].first >> cus[i].second;
        if(cus[i].first < 0){
            l[il] = cus[i];
            l[il].first = -cus[i].first;
            ++il;
        }
        else{
            r[ir] = cus[i];
            ++ir;
        }
    }
    // sort function rearrange by the first element
    sort(l, l + il);
    sort(r, r + ir);
    // for (int i = 0; i < il; ++i){
    //     cout << l[i].first << "_" << l[i].second<<' ';
    // }
    // for (int i = 0; i < ir; ++i){
    //     cout << r[i].first << "_" << r[i].second<<' ';
    // }
    // for (int i = 0; i < il+ir; ++i){
    //     cout << cus[i].first << "_" << cus[i].second<<' ';
    // }
    
    long long cost_l = PMcost(l, il);
    long long cost_r = PMcost(r, ir);
    cout << cost_l + cost_r;

    return 0;
}
