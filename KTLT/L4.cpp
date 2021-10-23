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
    int i = 0;
    while(str[len] != '\0'){
        ++len;
    }
    while(str[i] != '\0'){
        if (str[i] == c){
            int j = i;
            while (str[j] != '\0'){
                str[j] = str[j + 1];
                ++j;
            }
        } else{
            ++i;
        }
    }
    cout << str << endl;
}
