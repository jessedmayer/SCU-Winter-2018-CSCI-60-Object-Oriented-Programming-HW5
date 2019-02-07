#include <iostream>

using namespace std;

template <typename T>
class Set{
public:
    Set();
    Set(T b[], int size);       //creates a set object from an array of type T and a size of type int
    int getLength();
    int* getPointer();          //returns a pointer that points to the address of the first value of the dynamic array
    void Add(T item);
    void output();
private:
    T* a;
    int length;
};

template <typename T>
Set<T>::Set(){
}

template <typename T>
Set<T>::Set(T b[], int size) {
    length=size;
    a=new T[length];
    for(int i=0; i<length; i++){
        a[i]=b[i];
    }
}

template <typename T>
int Set<T>::getLength() {
    return length;
}

template <typename T>
int* Set<T>::getPointer(){
    int* p;
    p=a;
    return p;
}

template <typename T>
void Set<T>::Add(T item) {
    int* temp = new int[length+1];      //creates temporary dynamic array of size +1 longer than the original array
    for(int i=0; i<length; i++){        //increments through temp array setting all but the last element to the equivalent elements from the original
        temp[i]=a[i];
    }
    temp[length]=item;                  //sets the last element of the temp array to the desired addition to the set
    delete [] a;                        //deletes the original array
    a = temp;                           //sets the original array to the temp array
    length++;                           //increments the length of the new array
}

template <typename T>
void Set<T>::output() {                 //increments through array outputting each element
    for(int i=0; i<length; i++){
        cout << a[i] <<endl;
    }
}

int main(){
    int b[5]={1,2,3,4,5};
    int c=6;
    Set<int> s1(b,5);
    cout << s1.getLength() <<endl;
    //s1.output();
    s1.Add(c);
    cout << s1.getLength() <<endl;
    s1.output();
    cout << s1.getPointer() <<endl;


    return 0;
}