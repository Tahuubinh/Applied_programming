#include <bits/stdc++.h>
using namespace std;

bool isPali(string s, int i, int j){
    if (i >= j){
        return true;
    }
    if (s[i] != s[j]){
        return false;
    }
    return isPali(s, i + 1, j - 1);
};

int main(){
    string s1 = "aabcbaa";
    string s2 = "aan";
    cout << isPali(s1, 0, s1.size() - 1) << endl;
    cout << isPali(s2, 0, s2.size() - 1) << endl;
    return 0;
}