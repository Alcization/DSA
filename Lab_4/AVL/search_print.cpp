
void printInorder(){
    if(root == nullptr) return;
    Node*x = root;
    root = root->pLeft;
    printInorder();
    root = x;
    cout << root->data << " ";
    root = root->pRight;
    printInorder();
    root = x;
}

bool search(const T &value){
    Node* x = root;
    while(x)
    {
        if(x->data == value) return true;
        else if(x->data > value) x = x->pLeft;
        else x = x->pRight;
    }
    return false;
}