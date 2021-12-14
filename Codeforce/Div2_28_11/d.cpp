#include <bits/stdc++.h>
using namespace std;
#define endl '\n';
#define pii pair<int, int>
using ll = long long;
using ull = unsigned long long;

int n, d;
int x[1001], y[1001];
unordered_set<int> ini;
vector<unordered_set<int>> v;

int where(int x, vector<unordered_set<int>> &v){
    int size = v.size();
    for (int i = 0; i < size; ++i){
        if (v.at(i).find(x) != v.at(i).end()){
            return i;
        }
    }
    return -1;
}

int main(){
    ios_base :: sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> n >> d;
    for (int i = 1; i <= d; ++i){
        cin >> x[i] >> y[i];
    }
    ini = {x[1], y[1]};
    v.push_back(ini);
    int res = 1;
    for (int i = 2; i <= d; ++i){
        int xt = where(x[i], v);
        int yt = where(y[i], v);
        if (xt == -1 && yt == -1){
            ini = {x[i], y[i]};
            v.push_back(ini);
            cout << res << endl; continue;
        }
        if (xt == -1){
            v.at(yt).insert(x[i]);
            res = max(res, (int)v.at(yt).size());
            cout << res << endl; continue;
        }
        if (yt == -1){
            v.at(xt).insert(y[i]);
            res = max(res, (int)v.at(xt).size());
            cout << res << endl; continue;
        }
        if (xt != yt){
            set_union(v.at(xt).begin(), v.at(xt).end(),
                v.at(yt).begin(), v.at(yt).end(),
                std::inserter(v.at(xt), v.at(xt).begin()));
            v.erase(v.begin() + yt);
            res = max(res, (int)v.at(yt).size());
            cout << res << endl; continue;
        }
        int j = i + 1;
        while (j <= n){
            int xt2 = where(x[j], v);
            int yt2 = where(y[j], v);
            if (xt2)
        } 
    }


    // set<int> odd = { 1, 3, 5 };
    // set<int> even = { 2, 4, 6 };
    // set<int> c = { 1, 4, 6 };
    // v.push_back(odd);
    // v.push_back(even);
    // v.push_back(c);
    // v.erase(v.begin() + 1);
    // set<int> temp = v.at(1);
    // for (auto const &e: temp) {
    //     std::cout << e << ' ';
    // }
    
    // std::set<int> odd = { 1, 3, 5 };
    // std::set<int> even = { 2, 4, 6 };

    // std::set_union(odd.begin(), odd.end(),
    //             even.begin(), even.end(),
    //             std::inserter(odd, odd.begin()));
 
    // for (auto const &e: even) {
    //     std::cout << e << ' ';
    // }
    
    
    return 0;
}
