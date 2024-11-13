#include <iostream>
using namespace std;

class BSTNode {
public: 
    int val; 
    BSTNode *left; 
    BSTNode *right; 
    BSTNode() {
        this->left = this->right = nullptr;
    } 
    BSTNode(int val) {
        this->val = val;
        this->left = this->right = nullptr;
    } 
    BSTNode(int val, BSTNode*& left, BSTNode*& right) {
        this->val = val;
        this->left = left;
        this->right = right;
    } 
};



int singleChild(BSTNode* root) {
    // STUDENT ANSWER
    if (root == nullptr) return 0;
    if (root->left == nullptr && root->right != nullptr) return 1 + singleChild(root->right);
    if (root->left != nullptr && root->right == nullptr) return 1 + singleChild(root->left);
    return singleChild(root->left) + singleChild(root->right);
}

