#include <iostream>

using namespace std;

double* maximum(double* a, int size){

    double *max;

    max = a;

    if (a==NULL) return NULL;



    for (int i = 1; i < size; ++i){
        if (*(a + i) > *max){
            max = a+i;
        }
    }



    return max;

}

int main() {

    double arr[] = {50., 10., 2., -7., 25., 60.};
    double* max = maximum(arr, 6);
    printf("%.0f", *max);

    return 0;

}

