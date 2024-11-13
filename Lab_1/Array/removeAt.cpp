#include <iostream>
using namespace std;

template <class T>
class ArrayList {
protected:
    T* data;        // dynamic array to store the list's items
    int capacity;   // size of the dynamic array
    int count;      // number of items stored in the array

public:
    ArrayList(){capacity = 5; count = 0; data = new T[5];}
   ~ArrayList(){ delete[] data; }    
    void    add(T e);
    void    add(int index, T e);
    int     size();
    bool    empty();
    void    clear();
    T       get(int index);
    void    set(int index, T e);
    int     indexOf(T item);
    bool    contains(T item);
    T       removeAt(int index);
    bool    removeItem(T item);
    void    ensureCapacity(int index);
};


template<class T>
T ArrayList<T>::removeAt(int index){
    if (index < 0 || index >= this->count) throw "index is out of range";
    T res = data[index];
    if (index == this->count - 1){
        this->count--;
        return res;
    }
    for (int i = index; i < this->count - 1; i++){
        data[i] = data[i+1];
    }
    count--;
    return res;
}

template<class T>
bool ArrayList<T>::removeItem(T item){
     /* Remove the first apperance of item in array and return true, otherwise return false */
     for (int i = 0; i < this->count; i++){
         if (data[i] == item && i != this->count - 1){
             for (int j = i; j < this->count - 1; j++){
                 data[j] = data[j+1];
             }
             this->count--;
             return true;
         }
         else if (data[i] == item && i == this->count - 1){
             this->count--;
             return true;
         }
     }
     return false;
}

template<class T>
void ArrayList<T>::clear(){
    /* 
        Delete array if array is not NULL
        Create new array with: size = 0, capacity = 5
    */
    if (data != NULL){
        delete(data);
    }
    this->capacity = 5;
    this->count = 0;
}
