#include <iostream>

using namespace std;

template <typename T>
void search(const T a[], int first, int last, T key, bool& found, int& location){
    int mid;
    if (first > last){
        found=false;
    }
    else{
        mid = (first+last)/2;                                   //sets the middle to be half way between the first and last

        if(key==a[mid]){
            found=true;
            location=mid;
        }
        else if (key < a[mid]){
            search(a, first, mid-1, key, found, location);      //searches  down the array
        }
        else if (key > a[mid]){
            search(a, mid+1, last,  key, found, location);      //searches  up the array
        }
    }
}




int main() {
    int a[5]={3,4,5,6,7};
    int key(2),location;
    bool found;
    search(a, 0, 4, key, found, location);
    cout << found <<endl;
    cout << location <<endl;

    return 0;
}
