#include <bits/stdc++.h>
using namespace std;



int main(){
    ios_base :: sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    string s;
    cin >> s;
    stack<char> st;
    for (int i = 0; i < s.size(); ++i){
        if (st.empty() || st.top() != s[i]){
            st.push(s[i]);
            continue;
        }
        st.pop();
    }
    if (st.empty()){
        cout << "YES";
    } else{
        cout << "NO";
    }

    
    return 0;
}
