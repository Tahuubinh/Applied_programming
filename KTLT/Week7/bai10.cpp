#include <bits/stdc++.h>

using namespace std;
void alloMem(int ***mt, int n){
    *mt = new int*[n];
    for (int i = 0; i < n; ++i){
        (*mt)[i] = new int[n];
    }
}


/*void inputMem(int **mt, int n){
    //#Input elements of the matrix

    for (int i = 0; i < n; ++i){
        for (int j = 0; j < n; ++j){
            scanf("%d", &mt[i][j]);
        }
    }

}*/

void outputMem(int **mt, int n){
    //# Print all elements of the matrix

    for (int i = 0; i < n; ++i){
        for (int j = 0; j < n; ++j){
            printf("%d ", mt[i][j]);
        }
        printf("\n");
    }

}

void freeMem(int **mt, int n){
    //# Free memory

    for (int i = 0; i < n; ++i){
        delete [] mt[i];
    }
    delete [] mt;
}

void tongMem(int** &tong, int** mt1, int** mt2, int n){
    for (int i = 0; i < n; ++i){
        for (int j = 0; j < n; ++j){
            tong[i][j] = mt1[i][j] + mt2[i][j];
        }
    }
}

void tichMem(int** &tich, int** mt1, int** mt2, int n){
    for (int i = 0; i < n; ++i){
        for (int j = 0; j < n; ++j){
            tich[i][j] = 0;
            for (int k = 0; k < n; ++k){
                tich[i][j] += mt1[i][k] * mt2[k][j];
            }
        }
    }
}

int main(){
    int n, **mt1, **mt2, **tong, **tich;
    cin >> n;
    alloMem(&mt1, n);
    alloMem(&mt2, n);
    alloMem(&tong, n);
    alloMem(&tich, n);
    for (int i = 0; i < n; ++i){
        for (int j = 0; j < n; ++j){
            cin >> mt1[i][j];
        }
    }
    for (int i = 0; i < n; ++i){
        for (int j = 0; j < n; ++j){
            cin >> mt2[i][j];
        }
    }


    tongMem(tong, mt1, mt2, n);
    tichMem(tich, mt1, mt2, n);

    outputMem(tong, n);
    outputMem(tich, n);

    freeMem(tong, n);
    freeMem(tich, n);
    freeMem(mt1, n);
    freeMem(mt2, n);
    return 0;
}

