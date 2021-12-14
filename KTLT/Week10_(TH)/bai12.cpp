#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(){
    int key, value;
    vector<pair<int, int>> vpair;
    while (cin >> key >> value){
        vpair.push_back(make_pair(key, value));
    }
    sort(vpair.begin(), vpair.end(), [](pair<int, int> a, pair<int, int> b){
        if (a.second > b.second){
            return true;
        }
        if (a.second < b.second){
            return false;
        }
        return a.first > b.first;
    });
    int n = vpair.size();
    for (int i = 0; i < n; ++i){
        cout << vpair[i].first << ' ' << vpair[i].second << endl;
    }
    return 0;
}
