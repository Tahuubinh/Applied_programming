#include <bits/stdc++.h>
using namespace std;
#define endl '\n';
#define pii pair<int, int>
#define fr(i,x,y) for(int i = x; i <= y; ++i)
using ll = long long;
using ull = unsigned long long;

const int N = 10001;
int n;
vector<pii> job_queue;
int d, p, ans;
int a[N], slot[N];

// bool compare(pii a, pii b){
//     if (a.first < b.first){
//         return true;
//     }
//     if (a.first == b.first){
//         if (a.second < b.second){
//             return true;
//         }
//     }
//     return false;
// }

bool compare(pii a, pii b){
    if (a.second > b.second){
        return true;
    }
    return false;
}

int main(){
    ios_base :: sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> n;
    fr(i, 1, n){
        cin >> d >> p;
        job_queue.push_back(make_pair(d, p));
    }
    job_queue.resize(n);
    sort(job_queue.begin(), job_queue.end(), compare);
    // for (pii x: job_queue){
    //     cout << x.first << ' ' << x.second << endl;
    // }
    // int small = job_queue.at(0).first;
    // int big = job_queue.at(n - 1).first;
    // int temp = job_queue.at(0).second;
    // for (pii x: job_queue){
    //     if (x.first == small){
    //         temp = x.second;
    //     } else {
    //         break;
    //     }
    // }
    // fr(i, 1, small){
    //     a[i] = temp;
    // }
    // for (i, small, big){

    // }
    fr(i, 0, n - 1){
        for (int j = min(n - 1, job_queue[i].first) - 1; j >= 0; --j){
            if (!slot[j]){
                slot[j] = true;
                ans += job_queue[i].second;
                break;
            }
        }
    }
    
    cout << ans;
    
    return 0;
}
