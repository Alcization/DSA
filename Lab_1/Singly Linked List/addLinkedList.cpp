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

class LLNode {
public:
    int val;
    LLNode* next;
    LLNode() : val(0), next(nullptr) {}
    LLNode(int val, LLNode* next = nullptr) : val(val), next(next) {}
};

LLNode* addLinkedList(LLNode* l0, LLNode* l1) {
    LLNode* result = new LLNode(); 
    LLNode* current = result;
    int carry = 0;
    while (l0 || l1) 
    {
        int sum = carry;
        if (l0) 
        {
            sum += l0->val;
            l0 = l0->next;
        }
        if (l1) 
        {
            sum += l1->val;
            l1 = l1->next;
        }
        carry = sum / 10; 
        sum %= 10; 
        current->next = new LLNode(sum);
        current = current->next;
    }
    if (carry > 0) current->next = new LLNode(carry);
    return result->next; 
}

