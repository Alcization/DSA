int count(Node* node) 
{   
    if (node == NULL) return 0;
    else if (node->pLeft != NULL && node->pRight != NULL) return count(node->pLeft) + count(node->pRight) + 1;
    else return count(node->pLeft) + count(node->pRight);
}

int countTwoChildrenNode()
{
    return count(root);
}