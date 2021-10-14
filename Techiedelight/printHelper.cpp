#include <bits/stdc++.h>
#include <io.h>
#include <fcntl.h>

using namespace std;

void printHelper(int num_slides, int base, int slide_per_page){
    int slide_per_a4 = 2 * slide_per_page;
    --base;
    cout << "Odd page (Mat truoc)"<<endl;
    for (int i = 1; i <= num_slides; ++i){
        if (i % slide_per_a4 > 0 && i % slide_per_a4 <= slide_per_page){
            cout << i + base << ", ";
        }
    }
    cout << endl;
    cout << "Even page (Mat sau)"<<endl;
    for (int i = 1; i <= num_slides; ++i){
        if (i % slide_per_a4 == 0 || i % slide_per_a4 > slide_per_page){
            cout << i + base << ", ";
        }
    }
}

int main(){
    int num_slides;
    int base;
    int slide_per_page;
    cout << "This little program help input pages to print!" << endl;
    cout << "Huong dan su dung:" << endl;
    cout << "Slides per page: {So slides se in}" << endl;
    cout << "Base: {Trang dau tien}" << endl;
    cout << "Slides per page: {So slide xuat hien tren mot mat giay}" << endl;
    cout << "------------------------------" << endl;
    cout << "Number of slides: ";
    cin >> num_slides;
    cout << "Base: ";
    cin >> base;
    cout << "Slides per page:  ";
    cin >> slide_per_page;
    printHelper(num_slides, base, slide_per_page);

    cout << endl;
    system("pause");
    return 0;
}