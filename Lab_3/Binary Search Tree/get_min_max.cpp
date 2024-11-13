// STUDENT ANSWER BEGIN
// You can define other functions here to help you.
T minRec(Node* node) {
    if (node->pLeft == nullptr) return node->value;
    else return minRec(node->pLeft);
}

T maxRec(Node* node) {
    if (node->pRight == nullptr) return node->value;
    else return maxRec(node->pRight);
}

T getMin() {
    //TODO: return the minimum values of nodes in the tree.
    return minRec(this->root);
}

T getMax() {
    //TODO: return the maximum values of nodes in the tree.
    return maxRec(this->root);
}

// STUDENT ANSWER END
