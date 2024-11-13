LLNode* reverseLinkedList(LLNode* head) {
    LLNode* prev = nullptr;
    LLNode* current = head;
    LLNode* next = nullptr;
    while (current != nullptr) {
        next = current->next;   
        current->next = prev;   
        prev = current;        
        current = next;
    }
    return prev;  
}