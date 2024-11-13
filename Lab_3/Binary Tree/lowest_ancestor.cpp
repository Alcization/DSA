#include <iostream>
#include <utility>
#include <queue>
#include <stack>
using namespace std;

class BTNode {
    public: 
        int val; 
        BTNode *left; 
        BTNode *right; 
        BTNode() {
            this->left = this->right = NULL;
        } 
        BTNode(int val) {
            this->val = val;
            this->left = this->right = NULL;
        } 
        BTNode(int val, BTNode*& left, BTNode*& right) {
            this->val = val;
            this->left = left;
            this->right = right;
        } 
};


BTNode* lowestCommonAncestor(BTNode* root, BTNode* p, BTNode* q) 
{
    if (!root || root == p || root == q) return root;
    BTNode* left = lowestCommonAncestor(root->left, p, q);
    BTNode* right = lowestCommonAncestor(root->right, p, q);
    return !left ? right : !right ? left : root;
}

BTNode* get_node(BTNode* node, int key)
{
    if (node == nullptr)
        return nullptr;
    if (node->val == key)
        return node;
    BTNode* res1 = get_node(node->left, key);
    if(res1) return res1; 
    BTNode* res2 = get_node(node->right, key);
    return res2;
}

int lowestAncestor(BTNode* root, int a, int b) 
{
    BTNode* p = root;
    BTNode* q = root;
    p = get_node(root, a);
    q = get_node(root, b);
    BTNode* result = lowestCommonAncestor(root, p, q);
    return result->val;
}

