#include <iostream>

using namespace std;

int counteven(int a[], int n){
    int cnt = 0;
    for (int i = 0; i < n; ++i){
        if (a[i] % 2 == 0){
            ++cnt;
        }
    }
    return cnt;
}

int main() {

    int arr[] = {1, 5, 4, 8, 10, 6, 7, 2};
    cout << counteven(arr, 8);

    return 0;

}
