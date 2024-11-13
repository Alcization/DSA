int count(Node* node) 
{   
    if (node == nullptr) return 0;
    else if (node->pLeft == nullptr && node->pRight == nullptr) return node->value + count(node->pLeft) + count(node->pRight) ;
    else return count(node->pLeft) + count(node->pRight);
}

int sumOfLeafs() {
    return count(root);
}