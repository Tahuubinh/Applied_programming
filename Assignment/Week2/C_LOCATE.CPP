#include <bits/stdc++.h>

using namespace std;
int t;
int dist[2002][2002]; // Cannot be in main but i do not know why

int main(){
    ios_base :: sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    
    cin >> t;

    while(t--){        
        int l, c, l_dist, c_dist, temp, max_dist;
        cin >> l >> c;
        vector<pair<int, int>> image_1, image_2; // only store 1
        memset(dist, 0, sizeof(dist));
        for (int i = 0; i < l; ++ i){
            for (int j = 0; j < c; ++j){
                cin >> temp;
                if (temp){
                    image_1.push_back({i, j});
                }
            }
        }
        
        for (int i = 0; i < l; ++ i){
            for (int j = 0; j < c; ++j){
                cin >> temp;
                if (temp){
                    image_2.push_back({i, j});
                }
            }
        }

        int res = 0;
        int len_1 = image_1.size();
        int len_2 = image_2.size();

        // while(len_1--){
        //     cout << image_1[len_1].first << ' ' << image_1[len_1].second << endl;
        // }
        
        // while(len_1--){
        //     while(len_2--){ // len_2 be 0 and stop
        //         l_dist = image_1[len_1].first - image_2[len_2].first + MAX;
        //         c_dist = image_1[len_1].second - image_2[len_2].second + MAX;
        //         dist[{l_dist, c_dist}]++;
        //         //cerr << "a " << l_dist << "a " << c_dist << dist[{l_dist, c_dist}];
        //         cerr << "a " << image_1[len_1].first << "a " << image_1[len_1].second << 'a';
        //         if (dist[{l_dist, c_dist}] > max){
        //             max = dist[{l_dist, c_dist}];
        //         }
        //     }
        // }

        for (int i = 0; i<len_1; ++i){
            for (int j = 0; j<len_2; ++j){
                l_dist = image_1[i].first - image_2[j].first + 1001;
                c_dist = image_1[i].second - image_2[j].second + 1001;
                ++dist[l_dist][c_dist];
            }
        }
        for (int i = 0; i < 2002; ++i){
            max_dist = *max_element(dist[i], dist[i] + 2002);
            if (res < max_dist){
                res = max_dist;
            }
        }

        cout << res << endl;
    }
    

    
    return 0;
}
