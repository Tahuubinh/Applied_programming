#include <bits/stdc++.h>
using namespace std;



int main(){
    int n;
    cin >> n;
    int* arr = new int[n];
    int even = 0;
    int odd = 0;
    int eind = 0, oind = 0;
    int temp;
    for (int i = 0; i < n; ++i){
        cin >> temp;
        arr[i] = temp;
        if (arr[i] % 2){
            ++odd;
        } else{
            ++even;
        }
    }
    int* arre = new int[even];
    int* arro = new int[odd];
    for (int i = 0; i < n; ++i){
        if (arr[i] % 2){
            arro[oind] = arr[i];
            ++oind;
        } else{
            arre[eind] = arr[i];
            ++eind;
        }
    }
    cout << endl;
    for (int i = 0; i < even; ++i){
        cout << arre[i] << ' ';
    }
    cout << endl;
    for (int i = 0; i < odd; ++i){
        cout << arro[i] << ' ';
    }

    system("pause");
    return 0;
}
