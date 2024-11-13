void breadthFirstSearch(Node *root) {
    if (root == NULL) return;
    queue<Node*> bf_queue;
    bf_queue.push(root);  
    while(!bf_queue.empty()) {
        Node* current = bf_queue.front();
        bf_queue.pop();  
        cout<<current->value<<" ";
        if(current->pLeft != NULL) {
            bf_queue.push(current->pLeft);
        }
        if(current->pRight != NULL) {
            bf_queue.push(current->pRight);
        }
    }
}

void BFS()
{
    breadthFirstSearch(root);
}