#include <bits/stdc++.h>
using namespace std;

int n;
string command;
string param;
int a[202];
vector<string> dir;

int main(){
    ios_base :: sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    cin >> n;
    while(n--){
        cin >> command;
        if (command == "pwd"){
            cout << '/';
            //cout << '\n' << 'a' << dir.size() << dir[0];
            for (long long i = 0; i < dir.size(); ++i){
                cout << dir[i] << '/';
            }
            cout << '\n';
            continue;
        }
        // Then if command is cd
        cin >> param;
        int pos = 0;
        if (param[0] == '/'){            
            dir.clear();
            a[pos] = 0;
            if (param.size() == 1){
                continue;
            }
        }  else{    
            // Not absolute path, relative path
            a[pos] = -1;
        }
        ++pos;
        for (int i = 1; i < param.size(); ++i){
            if (param[i] == '/'){
                a[pos] = i;
                ++pos;
            }
        }
        for (int i = 1; i < pos; ++i){
            string temp = param.substr(a[i - 1] + 1, a[i] - a[i - 1] - 1);
            if (temp == ".."){
                if (dir.empty()){
                    continue;
                }
                dir.pop_back();
                continue;
            }
            dir.push_back(temp);
        }
        string temp = param.substr(a[pos - 1] + 1);
        if (temp == ".."){
            if (dir.empty()){
                continue;
            }
            dir.pop_back();
        } else{
            dir.push_back(temp);
        }       
    } 

    
    return 0;
}



// #include <iostream>
// #include <stdio.h>
// #include <math.h>
// #include <algorithm>
// #include <string>
// using namespace std;
 
// int main()
// {
//     ios_base :: sync_with_stdio(0);
//     cin.tie(0); cout.tie(0);
// 	int n,m,k;
// 	cin>>n;
// 	string s,t="/",u;
// 	for (int i=0; i<n; i++)
// 	{
// 		cin>>s;
// 		if (s=="pwd") {cout<<t<<endl;}
// 		else
// 		{
// 			cin>>s;
// 			if (s[0]=='/') {t="/"; s.erase(0,1);}
 
// 			while (s.length()>0)
// 			{
// 				while (s.length()>0 && s[0]!='/')
// 				{
// 					u+=s[0];
// 					s.erase(0,1);
// 				}
// 				if (u=="..")
// 				{
// 					t.erase(t.length()-1,1);
// 					while (t[t.length()-1]!='/') {t.erase(t.length()-1,1);}
// 				}
// 				else
// 				{
// 					t=t+u;
// 					t=t+"/";
// 				}
// 				s.erase(0,1);
// 				u="";
// 			}
// 		}
// 	}
// }