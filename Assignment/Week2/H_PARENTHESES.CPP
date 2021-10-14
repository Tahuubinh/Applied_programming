#include <bits/stdc++.h>
using namespace std;

int t;
string str;

bool isPair(char c1, char c2){
    if (c1 == '(' && c2 == ')'){
        return true;
    }
    if (c1 == '[' && c2 == ']'){
        return true;
    }
    if (c1 == '{' && c2 == '}'){
        return true;
    }
    return false;
}

bool check(string str){
    stack<char> st;
    for (char c:str){
        if (st.empty()){
            st.push(c);
        }
        else if (isPair(st.top(), c)){
            st.pop();
        }
        else {
            st.push(c);
        }
    }
    return st.empty();
}

int main(){
    ios_base :: sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    cin >> t;
    cin.ignore();
    while(t--){
        getline(cin, str);
        cout << check(str) << '\n';
    }
    


    

    
    return 0;
}
