#include <iostream>
#include <sstream>
using namespace std;
class LinkedList {
    public: 
        class Node;
    private:
        Node* head;
        Node* tail;
        int size;
    public: 
        class Node {
            private: 
                int value;
                Node* next;
                friend class LinkedList;
            public:
                Node() {
                    this->next = NULL;
                }
                Node(Node* node) {
                    this->value = node->value;
                    this->next = node->next;
                }
                Node(int value, Node* next = NULL) {
                    this->value = value;
                    this->next = next;
                }
        };
        LinkedList(): head(NULL), tail(NULL), size(0) {};
	void partition(int k);
};

void LinkedList::partition(int k) {
    Node* h = head;
    int size = this->size;
    int* arr = new int[size];
    int move = 0;
    for (h = head; h != NULL; h = h->next) 
    {
        if (h->value < k) {arr[move] = h->value; ++move;}
    }
    for (h = head; h != NULL; h = h->next) 
    {
        if (h->value == k) {arr[move] = h->value; ++move;}
    }
    for (h = head; h != NULL; h = h->next) 
    {
        if (h->value > k) {arr[move] = h->value; ++move;}
    }
    int i = 0;
    for (h = head; h != NULL; h = h->next) 
    {
        h->value = arr[i];
        ++i;
    }
    tail->value = arr[size - 1];
    delete[] arr;
    return;

}