template <class T>
void SLinkedList<T>::add(const T& e) {
    Node* newNode = new Node(e, nullptr);
    if (head == nullptr) {
        head = newNode;
        tail = newNode;
    } else {
        tail->next = newNode;
        tail = newNode;
    }
    count++;
    
}

template<class T>
void SLinkedList<T>::add(int index, const T& e) {
    if (index < 0 || index > count) {
        throw std::out_of_range("Index out of range");
    }
    if (index == count) {
        // Adding at the end is the same as using the add(T e) method.
        add(e);
    } else if (index == 0) {
        // Adding at the beginning.
        Node* newNode = new Node(e, head);
        head = newNode;
        count++;
    } else {
        // Adding at a specific index.
        Node* newNode = new Node(e, nullptr);
        Node* current = head;
        for (int i = 0; i < index - 1; i++) {
            current = current->next;
        }
        newNode->next = current->next;
        current->next = newNode;
        count++;
    }
}

template <class T>
int SLinkedList<T>::size() {
    return count;
}