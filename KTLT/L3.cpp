#include <bits/stdc++.h>
using namespace std;



int main(){
    char str[20];
    gets(str);
    int find[20];
    int indexfind = 0;
    int len = 0;
    char c;
    cin >> c;
    for (int i = 0; i < 20; ++i){
        if(str[i] == '\0'){
            break;
        }        
        ++len;
        if (str[i] == c){
            find[indexfind] = i;
            ++indexfind;
        }
    }
    if (indexfind == 0){
        cout << "Not found";
    } else{
        cout << "First: " << find[0] << endl;
        cout << "Last: " << find[indexfind - 1] << endl;
        for (int i = 0; i < indexfind; ++i){
            cout << find[i] << ' ';
        }
    }
    
}
