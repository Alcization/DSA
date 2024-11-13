#include <iostream>
#include <unordered_map>
using namespace std;


struct ListNode 
{
    int val;
    ListNode *left;
    ListNode *right;
    ListNode(int x = 0, ListNode *l = nullptr, ListNode* r = nullptr) : val(x), left(l), right(r) {}
};


ListNode* reverse(ListNode* head, int a, int b) 
{
    ListNode* travel = head;
    ListNode* prev;
    ListNode* trav = head;
    int count = b - a + 1;
    for (int j = 1; j <= b; j++) trav = trav->right;
    if (a != 1) 
    {
        for (int i = 1; i < a; i++) travel = travel->right;
        prev = travel->left;
    } else prev = nullptr;

    ListNode* temp = NULL;
    ListNode* current = travel;
    while (current != NULL and count > 0) 
    {
        temp = current->left;
        current->left = current->right;
        current->right = temp;
        current = current->left;
        count--;
    }
    if (trav == nullptr and a == 1)
    {
        if (temp != NULL) head = temp->left;
        return head;
    } 
    if (trav != nullptr)
    {
        travel->right = trav;
        trav->left = travel;
    }

    if (temp != NULL and prev != nullptr) 
    {
        prev->right = temp->left;
        temp = temp->left;
        temp->left = prev;
    }
    
    return head;
}



