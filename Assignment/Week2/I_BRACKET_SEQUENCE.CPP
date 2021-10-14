#include <bits/stdc++.h>
using namespace std;

const int M = 1e5 + 2;
string s;
int cnt[M];
stack<int> st;
int most,l,r;
// The most, not the longest

int main(){
    ios_base :: sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    cin >> s;
    s = "%" + s;
    st.push(0);
    int len = s.size();
    for (int i = 1; i < len; ++i){
        
        // if (s[i] == '['){
        //     cnt[i] = cnt[i - 1] + 1;
        // }
        cnt[i] = cnt[i - 1] + (s[i] == '[');
        if (s[i] == '[' || s[i] == '('){
            st.push(i);
        } 
        else if (s[i] == ']' && s[st.top()] != '[' ||
                 s[i] == ')' && s[st.top()] != '('){
            st.push(i);
        } else {
            st.pop();
            if (most < cnt[i] - cnt[st.top()]){
                most = cnt[i] - cnt[st.top()];
                l = st.top() + 1;
                r = i - l + 1;

            }
        }
    }
    cout << most << '\n' << s.substr(l, r);
    // string str = "12345";
    // cout << str.substr(2,4);
    
    return 0;
}
