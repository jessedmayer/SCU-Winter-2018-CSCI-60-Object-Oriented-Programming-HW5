#include <iostream>

using namespace std;

template <typename T>
void search(const T a[], T key, bool& found, int& location){
    found=false;                                                //assume not found till its found
    for(int i=0; i<(sizeof(a)/sizeof(*a)); i++){                //increments through array looking for the key
        if(key==a[i]){
            found=true;
            location=i;                                         //notes the index location where the key is found
        }
    }
}




int main() {
    int a[5]={3,4,5,6,7};
    int key(4),location;
    bool found;
    search(a, key, found, location);
    cout << found <<endl;
    cout << location <<endl;

    return 0;
}
