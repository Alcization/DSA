#include <iostream>
using namespace std;
template <class T>
class Sorting {
public:
    /* Function to print an array */
    static void printArray(T *start, T *end)
    {
        long size = end - start + 1;
        for (int i = 0; i < size - 1; i++)
            cout << start[i] << ", ";
        cout << start[size - 1];
        cout << endl;
    }
    
    static void merge(T* left, T* middle, T* right);
    static void mergeSort(T* start, T* end);
};

struct ListNode {
    int val;
    ListNode* next;
    ListNode(int _val = 0, ListNode* _next = nullptr) : val(_val), next(_next) { }
};



ListNode* mergeLists(ListNode* a, ListNode* b){
    if(a == nullptr) return b;
    if(b == nullptr) return a;
    ListNode * result = new ListNode(0);
    ListNode* tmp = result;
    while(a || b)
    {
        if(!b || (a && a->val < b->val))
        {
            tmp->next = a;
            a = a->next;
            tmp = tmp->next;
        }
        else
        {
            tmp->next = b;
            b = b->next;
            tmp = tmp->next;               
        }
    }
    return result->next;
}

ListNode* midnode(ListNode* a)
{
    ListNode* tmp = a;
    while(tmp->next && tmp->next->next)
    {
        a = a->next;
        tmp = tmp->next->next;
    }
    tmp = a->next;  
    a->next = nullptr; 
    return tmp;
}
ListNode* mergeSortList(ListNode* head) {
    if(head == nullptr || head->next == nullptr) return head;
    ListNode* mid = midnode(head);
    head = mergeSortList(head);
    mid = mergeSortList(mid);
    return mergeLists(head,mid); 
}