#include <bits/stdc++.h>

using namespace std;

void printString(){
    string s;
    cin >> s;
    short len = s.length();
    if (len <= 10){
        cout << s << endl;
    }
    else{
        cout << s[0] + to_string(len-2) + s[len-1] << endl;
    }
}

int main(){
    short n;
    cin >> n;
    while(n --){
        printString();
    }
    return 0;
}
