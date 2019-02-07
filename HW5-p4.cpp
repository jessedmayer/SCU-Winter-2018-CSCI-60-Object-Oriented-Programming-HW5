#include <iostream>

using namespace std;

template <typename T>
class DynamicArray{
public:
    DynamicArray();
    DynamicArray(const DynamicArray& S);        //copy constructor that sets a new DynamicArray object to be equal to some source DynamicArray object
    int getSize();
    void addEntry(T entry);
    bool deleteEntry(T entry);                  //deletes a given entry from the array and shifts the index of the following elements accordingly
    T getEntry(int index);                      //returns the elements at a given index
    DynamicArray& operator =(DynamicArray b);   //overloads the = operator so that you can assign one DynamicArray object to be equal to another
    void destructor();                          //deletes the DynamicArray's array from the allocated memory
private:
    T* a;
    int size;
};

template <typename T>
DynamicArray<T>::DynamicArray() {
    a= nullptr;
    size=0;
}

template <typename T>
DynamicArray<T>::DynamicArray(const DynamicArray &S) {
    size=S.size;
    a=S.a;
}

template <typename T>
int DynamicArray<T>::getSize() {
    return size;
}

template <typename T>
void DynamicArray<T>::addEntry(T entry) {
    T* temp = new T[size+1];
    for(int i=0; i<size; i++){
        temp[i]=a[i];
    }
    temp[size]=entry;
    delete [] a;
    a = temp;
    size++;
}

template <typename T>
bool DynamicArray<T>::deleteEntry(T entry) {
    int index;
    bool found=0;
    for (int i = 0; i < size; i++) {
        if(a[i]==entry){
            index=i;
            found=1;
        }
    }
    if(found==0){
        return found;
    }
    else{
        size--;
        T* temp = new T[size];
        for(int i=0; i<index; i++){
            temp[i]=a[i];
        }
        for(int i=index; i<size; i++){
            temp[i]=a[i+1];
        }
        delete [] a;
        a = temp;
        return found;
    }
}

template <typename T>
T DynamicArray<T>::getEntry(int index) {
    if(index>size||index<0){
        return 0;
    }
    else{
        return a[index];
    }
}

template <typename T>
DynamicArray<T>& DynamicArray<T>::operator=(DynamicArray b) {
    if(size!=b.size){
        delete [] a;
        a = new T[b.size];
    }
    size=b.size;
    for(int i=0; i<size; i++){
        a[i]=b.a[i];
    }
    return *this;
}


template <typename T>
void DynamicArray<T>::destructor() {
    delete [] a;
}

int main(){
    DynamicArray<int>a1;
    a1.addEntry(7);
    a1.addEntry(2);
    a1.addEntry(3);
    cout<<a1.getSize()<<endl;
    cout<<a1.getEntry(0)<<endl;
    cout<<a1.getEntry(1)<<endl;
    cout<<a1.getEntry(2)<<endl;

    DynamicArray<int>a2(a1);
    a2.deleteEntry(2);
    cout<<a2.getEntry(0)<<endl;
    cout<<a2.getEntry(1)<<endl;

    DynamicArray<string>s1,s2;
    s1.addEntry("Stuff");
    s1.addEntry("Words");
    s1.addEntry("Things");
    s2=s1;
    cout << s2.getSize() <<endl;
    cout << s2.getEntry(0) <<endl;
    cout << s2.getEntry(1) <<endl;
    cout << s2.getEntry(2) <<endl;

    return 0;
}