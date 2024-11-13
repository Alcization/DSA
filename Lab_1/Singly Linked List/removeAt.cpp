#include <iostream>
#include <string>
#include <cstring>
#include <climits>
#include <utility>
#include <vector>
#include <list>
#include <stack>
#include <queue>
#include <map>
#include <unordered_map>
#include <set>
#include <unordered_set>
#include <functional>
#include <algorithm>
using namespace std;


template <class T>
class SLinkedList {
public:
    class Node; 
protected:
    Node* head;
    Node* tail;
    int count;
public:
    SLinkedList();
    ~SLinkedList();
    void    add(T e);
    void    add(int index, T e);
    int     size();
    bool    empty();
    int     size();
    void    clear();
    T       get(int index);
    void    set(int index, T e);
    int     indexOf(T item);
    bool    contains(T item);
    T       removeAt(int index);
    bool    removeItem(T item);
public:
    class Node {
    private:
        T data;
        Node* next;
        friend class SLinkedList<T>;
    public:
        Node() {
            next = 0;
        }
        Node(Node* next) {
            this->next = next;
        }
        Node(T data, Node* next = NULL) {
            this->data = data;
            this->next = next;
        }
    };
};

template <class T>
T SLinkedList<T>::removeAt(int index)
{
    Node *temp = this->head;
    int ans = 0, c = 0;
    if(index == 0){
        ans = this->head->data;
        this->head = this->head->next;
        this->count = this->count - 1;
        if(this->head == nullptr) this->tail = nullptr;
        delete(temp);
    }
    else
    {
        while(c+1 != index)
        {
            temp = temp->next;
            c++;
        }
        Node *t = temp->next;
        ans = t->data;
        temp->next = t->next;
        if(this->tail == t) this->tail = temp;
        this->count = this->count - 1;
        delete(t);
    }    
    return ans;
}

template <class T>
bool SLinkedList<T>::removeItem(const T& item)
{
    Node *temp = this->head;
    Node *current = this->head;
    while(current->data != item)
    {
        current = current->next;
        if(current == nullptr) return false;
    }
    if(this->head == current)
    {
        this->head = this->head->next;
        current = nullptr;
        this->count = this->count - 1;
        if(this->head == nullptr) this->tail = nullptr;
        delete(temp);
        return true;
    }
    else
    {
        while(temp->next != current) temp = temp->next;
        Node *t = temp->next; 
        temp->next = current->next;
        this->count = this->count - 1;
        if(this->tail == current) this->tail = temp;
        delete(t);
        return true;
    }
}

template<class T>
void SLinkedList<T>::clear()
{
    while(this->head != nullptr)
    {
        Node *temp = this->head;
        this->head = this->head->next;
        delete(temp);
    }
    this->tail = nullptr;
    this->count = 0;
}
