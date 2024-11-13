template <class T>
class SLinkedList {
public:
    class Node; // Forward declaration
protected:
    Node* head;
    Node* tail;
    int count;
public:
    SLinkedList(): head(NULL), tail(NULL), count(0);
    ~SLinkedList() { };
    void    add(T e);
    void    add(int index, T e);
    int     size();
    bool    empty();
    T       get(int index);
    void    set(int index, T e);
    int     indexOf(T item);
    bool    contains(T item);
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

template<class T>
T SLinkedList<T>::get(int index) {
    /* Give the data of the element at given index in the list. */
    if (index > count - 1) return -1;
    if (head != NULL)
    {
        Node* h = head;
        int idx = 0;
        if (index == 0) return head->data;
        if (index == count - 1 && tail != NULL) return tail->data;
        while (h)
        {
            if (idx == index) return h->data;
            h = h->next;
            ++idx;
        }
    }
    return -1;
}

template <class T>
void SLinkedList<T>::set(int index, const T& e) {
    /* Assign new value for element at given index in the list */
    if (head == NULL) return;
    if (index > count - 1) return;
    if (index == 0)
    {
        head->data = e;
        return;
    }
    if (index == count - 1 && tail != NULL)
    {
        tail->data = e;
        return;
    }
    int idx = 0;
    Node* h = head;
    while (h != nullptr)
    {
        if (idx == index)
        {
            h->data = e;
            return;
        }
        h = h->next;
        ++idx;
    }
}

template<class T>
bool SLinkedList<T>::empty() {
    /* Check if the list is empty or not. */
    if (count == 0) return true;
    return false;
    
}

template<class T>
int SLinkedList<T>::indexOf(const T& item) {
    /* Return the first index wheter item appears in list, otherwise return -1 */
    if (head == NULL) return -1;
    if (head->data == item) return 0;
    if (tail != NULL && tail->data == item) return count - 1;
    int idx = 0;
    Node* h = head;
    while (h)
    {
        if (h->data == item) return idx;
        h = h->next;
        ++idx;
    }
    return -1;
}

template<class T>
bool SLinkedList<T>::contains(const T& item) {
    /* Check if item appears in the list */
    if (indexOf(item) == -1) return false;
    return true;
}
