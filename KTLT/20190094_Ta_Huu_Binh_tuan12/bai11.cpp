#include <bits/stdc++.h>
using namespace std;
#define endl '\n';
#define pii pair<int, int>
using ll = long long;
using ull = unsigned long long;

const int M = 10001;
int n, r, temp, ind;
int a[M][M];
int route[M], visited[M], place[M];
string s, temps;
int dist, mindist;

void Try(int btr){
    if (btr == ind){
        //cout << "haha";
        if (a[place[btr - 1]][route[ind]]){
            dist += a[place[btr - 1]][route[ind]];
            if (dist < mindist){
                mindist = dist;
            }
            dist -= a[place[btr - 1]][route[ind]];
        }
    } else {
        for (int i = 2; i < ind; ++i){
            //cerr << place[btr - 1] << endl;
            if (!visited[route[i]] && a[place[btr - 1]][route[i]]){
                dist += a[place[btr - 1]][route[i]];
                if (dist + 1 >= mindist){
                    dist -= a[place[btr - 1]][route[i]];
                    continue;
                }
                visited[route[i]] = 1;
                place[btr] = route[i];
                //cerr << btr << ' ';
                Try(btr + 1);
                dist -= a[place[btr - 1]][route[i]];
                visited[route[i]] = 0;
            }
        }
    }
}

int main(){
    ios_base :: sync_with_stdio(0); cin.tie(0); cout.tie(0);
    
    cin >> n >> r;
    for (int i = 1; i <= n; ++i){
        for (int j = 1; j <= n; ++j){
            cin >> a[i][j];
        }
    }
    cin.ignore();
    while (r--){
        dist = 0;
        mindist = INT_MAX;
        getline(cin, s);
        ind = 1;
        int len = s.size();
        temps = "";
        for (int i = 0; i <= len; ++i){
            if (s[i] == ' '){
                temp = stoi(temps);
                route[ind] = temp;
                temps = "";
                ++ind;
            } else{
                temps += s[i];
            }
        }
        temp = stoi(temps);
        route[ind] = temp;
        for (int i = 0; i < 101; ++i){
            visited[i] = 0;
        }
        place[1] = route[1];
        place[ind] = route[ind];
        Try(2);
        if (mindist == INT_MAX){
            cout << 0 << endl;
        } else{
            cout << mindist << endl;
        }
        // for (int i = 1; i <= ind; ++i){
        //     cout << route[i] << ' ';
        // }
        //cout << ind;

    }
    // temps = "9943";
    // cout << stoi(temps);
    
    return 0;
}
