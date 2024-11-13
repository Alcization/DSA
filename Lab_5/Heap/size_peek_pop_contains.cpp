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
        delete[]elements;
    }
    void push(T item);
    
    bool isEmpty();
    bool contains(T item);
    T peek();
    T pop();
    int size();
    
    void printHeap()
    {
        cout << "Max Heap [ ";
        for (int i = 0; i < count; i++)
            cout << elements[i] << " ";
        cout << "]\n";
    }
private:
    void ensureCapacity(int minCapacity);
    void reheapUp(int position);
    void reheapDown(int position);
};


template<class T>
int Heap<T>::size()
{
    return count;
}

template<class T>
bool Heap<T>::isEmpty()
{
    return count == 0;
}

template<class T>
T Heap<T>::peek()
{
    if (count == 0) return -1;
    return elements[0];
}

template<class T>
bool Heap<T>::contains(T item)
{
    for(int i = 0 ; i < count; i++) if(item == elements[i]) return true;
    return false;
}

template<class T>
T Heap<T>::pop()
{
    if (count == 0) return -1;
    T result = elements[0];
    swap(elements[0], elements[count-1]);
    count--;
    reheapDown(0);
    return result;
}


