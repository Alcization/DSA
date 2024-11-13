#include <iostream>
#include <fstream>
#include <string>
#include <cstring>
#include <cmath>
#include <vector>
#include <algorithm>
using namespace std;
#define SEPARATOR "#<ab@17943918#@>#"
template<class T>
class Heap {
protected:
    T* elements;
    int capacity;
    int count;  
public:
    Heap()
    {
        this->capacity = 10;
        this->count = 0;
        this->elements = new T[capacity];
    }
    ~Heap()
    {
        delete[] elements;
    }
    void push(T item);
    void printHeap()
    {
        cout << "Max Heap [ ";
        for (int i = 0; i < count; i++)
            cout << elements[i] << " ";
        cout << "]";
    }
    
private:
    void ensureCapacity(int minCapacity); 
    void reheapUp(int position);
};


template<class T>
void Heap<T>::push(T item)
{
    ensureCapacity(capacity);
    elements[count] = item;
    reheapUp(count);
    count++;
}


template<class T>
void Heap<T>::ensureCapacity(int minCapacity)
{
    if (count < capacity) return;
    capacity++;
    T* new_elements = new T[capacity];
    for (int i = 0; i < count; i++) new_elements[i] = elements[i];
    delete[] elements;
    elements = new_elements;
}

template<class T>
void Heap<T>::reheapUp(int position)
{
    int n = (position - 1) / 2;
    if (position == 0 || elements[n] >= elements[position]) return;
    else 
    {
        swap(elements[n], elements[position]);
        reheapUp(n);
    }
}







