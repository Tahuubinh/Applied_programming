#include <bits/stdc++.h>
using namespace std;
#define endl '\n';
#define pll pair<long long, long long>
using ll = long long;

int n;
ll x, y;
pll input;
vector<pll> points, saves;

struct ans{
    ll x;
    ll y;
    ll dist;
};

ans makeAns(ll x, ll y, ll dist){
    ans temp;
    temp.x = x;
    temp.y = y;
    temp.dist = dist;
    return temp;
}

ans min(ans a, ans b){
    if (a.dist < b.dist){
        return a;
    }
    return b;
}

bool sortbysec(const pair<int,int> &a, const pair<int,int> &b)
{
    return (a.second < b.second);
}

ll sdist(pll &a, pll &b){
    return (a.first - b.first) * (a.first - b.first) +
            (a.second - b.second) * (a.second - b.second);
}

vector<pll> getLocal(int mid, int left, int right, ll dist){
    vector<pll> vlocal;
    for (int i = left; i <= right; ++i){
        if(sdist(points.at(i), points.at(mid)) < dist){
            vlocal.push_back(points.at(i));
        }
    }
    sort(vlocal.begin(), vlocal.end(), sortbysec);
    return vlocal;
}

ans minLocal(vector<pll> &local, ans dist, int left, int right){
    ans res = dist;
    int last = local.size() - 1;
    for (int i = 0; i < last; ++i){
        int compare = min(i + 7, last);
        for (int j = i + 1; j <= compare; ++j){
            if (sdist(local.at(i), local.at(j)) < res.dist){
                pll tempi = local.at(i);
                pll tempj = local.at(j);
                for (int k = 0; k < n; ++k){
                    ll x = points.at(k).first;
                    ll y = points.at(k).second;
                    if (tempi.first == x && tempi.second == y){
                        res.x = k;
                    }
                    if (tempj.first == x && tempj.second == y){
                        res.y = k;
                    }
                }
                res.dist = sdist(tempi, tempj);
            }
        }
    }
    return res;
}

ans dvc(int left, int right){
    if (left <= right){
        int mid = (right + left) >> 1;
        ans dvcl = dvc(left, mid - 1);
        ans dvcr = dvc(mid + 1, right);
        ans dist = min(dvcl, dvcr);
        vector<pll> local = getLocal(mid, left, right, dist.dist);
        return minLocal(local, dist, left, right);
    }
    return makeAns(0,0,LLONG_MAX);
}

int main(){
    ios_base :: sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> n;
    for (int i = 0; i < n; ++i){
        cin >> x >> y;
        input = make_pair(x, y);
        saves.push_back(input);
        points.push_back(input);
    }
    sort(points.begin(), points.end());
    cout << fixed << setprecision(6);
    ans res = dvc(0, n - 1);
    for (int k = 0; k < n; ++k){
        ll x = saves.at(k).first;
        ll y = saves.at(k).second;
        if (points.at(res.x).first == x && points.at(res.x).second == y){
            //cout << points.at(res.x).first << ' ' << points.at(res.x).second << endl;
            res.x = k;
            break;
        }
    }
    for (int k = 0; k < n; ++k){
        ll x = saves.at(k).first;
        ll y = saves.at(k).second;
        if (points.at(res.y).first == x && points.at(res.y).second == y){
            res.y = k;
            break;
        }
    }
    // cout << saves.at(0).first << ' ' << saves.at(0).second << endl;
    // cout << points.at(res.x).first << ' ' << points.at(res.x).second << endl;
    cout << res.x << ' ' << res.y << ' ' << sqrt(res.dist);
    

    
    return 0;
}
    // pll a = make_pair(5,6);
    // pll b = make_pair(1,3);
    // cout << sdist(a, b);
    // points.push_back(a);
    // points.push_back(b);
    // cout << sdist(points.at(0), points.at(1));
    // sort(points.begin(), points.end(), sortbysec);
    // cout << points.at(0).first;

    // cout << dvc(0, n - 1) << endl;
    // cout << sdist(points.at(3), points.at(4));
        // cerr << left << ',' << right << ' ' << mid << ':' << 
        // dvcl << ' ' <<
        //  dvcr << ' ' << minLocal(local, dist) << ' ' << 
        //  local.at(0).first << ' ' << 
        //  local.at(local.size() - 1).first << ' ' <<
        //  sdist(local.at(0), local.at(local.size() - 1))<<endl;
    // ans a = makeAns(1, 2, 3);
    // ans b = makeAns(1, 3, 2);
    // cout << a.dist << b.dist;
    // cout << min(a, b).y;