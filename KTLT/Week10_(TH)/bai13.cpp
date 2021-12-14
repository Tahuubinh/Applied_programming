#include <stdio.h>
#include <iostream>
#include <cstring>
#include <string>

using namespace std;

struct bigNum{
    char sign;
    char num[101];
};

void printNum(bigNum &a){
    cout << a.sign;
    int start;
    int i = 0;
    while (i < 101){
        if (a.num[i] != '0'){
            break;
        }
        ++i;
    }
    while (i < 101){
        cout << a.num[i];
        ++i;
    }
}

bool isBiggerAbs(bigNum a, bigNum b){
    for (int i = 0; i < 101; ++i){
        if (a.num[i] > b.num[i]){
            return true;
        }
        if (a.num[i] < b.num[i]){
            return false;
        }
    }
    return false;
}

bigNum addPos(bigNum a, bigNum b){
    bigNum tong;  
    memset(tong.num, '0', 101);
    int c = 0;
    int temp = 0;
    for (int i = 100; i >= 0; --i){
        temp = a.num[i] - 96 + b.num[i] + c;
        c = temp / 10;
        temp %= 10;
        tong.num[i] = temp + 48;
    }

    return tong;
}

bigNum subPos(bigNum a, bigNum b){
    bigNum hieu;  
    memset(hieu.num, '0', 101);
    int c = 0;
    int temp = 0;
    for (int i = 100; i >= 0; --i){
        temp = a.num[i] - b.num[i] - c;
        if (temp < 0){
            temp += 10;
            c = 1;
        } else{
            c = 0;
        }
        hieu.num[i] = temp + 48;
    }

    return hieu;
}

bigNum mulPos(bigNum a, bigNum b){
    bigNum tich;
    memset(tich.num, '0', 101);
    //tich.sign = '0';
    //int c = 0;
    int temp = 0;
    for (int i = 100; i >= 0; --i){
        bigNum tichphu;
        memset(tichphu.num, '0', 101);
        //tichphu.sign = '0';
        int k = i;
        int c = 0;
        int digit = b.num[i] - 48;
        for (int j = 100; j >= 0; --j){
            temp = (a.num[j] - 48) * digit + c;
            c = temp / 10;
            temp %= 10;
            tichphu.num[k] = temp + 48;
            if (!k){
                break;
            }
            --k;
        }
        tich = addPos(tich, tichphu);
    }

    // for (int i = 100; i >= 0; --i){
    //     bigNum tichphu;
    //     memset(tichphu.num, '0', 101);
    //     tichphu.sign = '0';
    //     int digitb = b.num[i] - 48;
    //     int k = i;
    //     int c = 0;
    //     int temp;
    //     for (int j = 100; j >= k; --j){
    //         int digita = a.num[j] - 48;
    //         temp = digita * digitb + c;
    //         c = temp / 10;
    //         tichphu.num[k] = c%10 + 48;
    //         --k;
    //         if (k < 0){
    //             break;
    //         }
    //     }
    //     tich = addPos(tich, tichphu);
    // }
    return tich;
}

bigNum operator + (bigNum a, bigNum b){
    bigNum tong;
    if (a.sign == '1' && b.sign == '1'){
        tong = addPos(a, b);
        tong.sign = '1';
    }
    else if (a.sign == '0' && b.sign == '0'){
        tong = addPos(a, b);
        tong.sign = '0';
    }
    else if (isBiggerAbs(a, b)){
        tong = subPos(a, b);
        tong.sign = a.sign;
    }
    else {
        tong = subPos(b, a);
        tong.sign = b.sign;
    }
    return tong;
}

bigNum operator - (bigNum a, bigNum b){
    bigNum hieu;
    if (a.sign != b.sign){
        hieu = addPos(a, b);
        hieu.sign = a.sign;
    }
    else if (isBiggerAbs(a, b)){
        hieu = subPos(a, b);
        hieu.sign = a.sign;
    }
    else {
        hieu = subPos(b, a);
        hieu.sign = 97 - b.sign;
    }
    return hieu;
}

bigNum operator * (bigNum a, bigNum b){
    bigNum tich = mulPos(a, b);
    if (a.sign == b.sign){
        tich.sign = '1';
    }
    else {
        tich.sign = '0';
    }
    return tich;
}

int main(){
    string temp;
    bigNum a, b;
    int start;
    memset(a.num, '0', 101);
    memset(b.num, '0', 101);

    cin >> temp;
    a.sign = temp[0];
    int lena = temp.size();
    start = 102 - lena;
    for (int i = 1; i < lena; ++i){
        a.num[start] = temp[i];
        ++start;
    }

    cin >> temp;
    b.sign = temp[0];
    int lenb = temp.size();
    start = 102 - lenb;
    for (int i = 1; i < lenb; ++i){
        b.num[start] = temp[i];
        ++start;
    }
    bigNum so3, so4;
    so3.sign = so4.sign = '1';
    memset(so3.num, '0', 101);
    memset(so4.num, '0', 101);
    so3.num[100] = '3';
    so4.num[100] = '4';
    bigNum res = a * b - so3 * a + so4 * b;
    printNum(res);

    //bigNum tong = addPos(a, b);
    // bigNum tong = a + b;
    // printNum(tong);
    // cout << endl;
    // bigNum hieu = a - b;
    // printNum(hieu);
    // cout << endl;
    //cout << hieu.sign << endl;
    // bigNum tong2 = addPos(a, b);
    // printNum(tong2);
    // cout << endl;
    // bigNum tich = a * b;
    // printNum(tich);
    


    return 0;
}
