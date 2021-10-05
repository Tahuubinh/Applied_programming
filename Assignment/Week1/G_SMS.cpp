#include <bits/stdc++.h>

using namespace std;
short save_count[10001];

void result_SMS(int i, unordered_map<char, int> sms){
    short count = 0;
    //char str[102];
    string str_cpp;    
    getline(cin, str_cpp);
    short len = str_cpp.length();
    char str[len + 1];
    strcpy(str, str_cpp.c_str());
    for (int i = 0; i < len; i++){
        count += sms[str[i]];
    }
    cout << "Case #" << i + 1 << ": " << count << endl;
}

int main(){
    unordered_map<char, int> sms;
    long long n;
    cin >> n;
    cin.ignore();
    sms['a'] = sms['d'] = sms['g'] = sms['j'] = sms['m'] = sms['p'] = sms['t'] = sms['w'] = 1;
    sms['b'] = sms['e'] = sms['h'] = sms['k'] = sms['n'] = sms['q'] = sms['u'] = sms['x'] = 2;
    sms['c'] = sms['f'] = sms['i'] = sms['l'] = sms['o'] = sms['r'] = sms['v'] = sms['y'] = 3;
    sms['s'] = sms['z'] = 4;
    sms[' '] = 1;
    // for (int i = 97; i <= 122; i ++){
    //     char a = i;
    //     cout << a << ' ' << sms[a] << ' ';
    // }
    // short count;
    // char str[102];
    // short len;
    for (int i = 0; i < n; i++){
        // gets(str);
        // count = 0;
        // len = strlen(str);
        // for (int i = 0; i < len; i++){
        //     count += sms[str[i]];
        // }
        // save_count[i] = count;
        // cout << "Case #" << i + 1 << ": " << count << endl;
        
        result_SMS(i, sms);
    }
    // for (int i = 0; i < n; i++){
    //     cout << "Case #" << i + 1 << ": " << save_count[i] << endl;
    // }
    // cout << "Enter a string: ";
    // gets(str);
    // cout << "You entered: " << str;
    // cout << "Enter a string: ";
    // gets(str);
    // cout << "You entered: " << str;
    
    return 0;
    
 
}
