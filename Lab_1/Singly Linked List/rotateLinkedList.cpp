LLNode* rotateLinkedList(LLNode* head, int k) {
    if (head == nullptr || k == 0) return head;
    int length = 1;
    LLNode* tail = head;
    while (tail->next != nullptr) {
        length++;
        tail = tail->next;
    }
    k %= length;
    if (k == 0) return head;
    LLNode* newTail = head;
    for (int i = 0; i < length - k - 1; i++) newTail = newTail->next;
    LLNode* newHead = newTail->next;
    newTail->next = nullptr;
    tail->next = head;
    return newHead;
}