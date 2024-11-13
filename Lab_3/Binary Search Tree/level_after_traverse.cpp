#include <iostream>
#include <vector>
#include <stack>
#include <queue>
#include <algorithm>
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

vector<int> levelAlterTraverse(BSTNode* root) {
    // STUDENT ANSWER
    vector<int> result;
    if (root == nullptr) return result;
    if (root->left == nullptr && root->right == nullptr)
    {
        result.push_back(root->val);
        return result;
    }
    // A queue for left to right traversal
    queue<BSTNode*> my_queue;
    // A stack for right to left traversal
    stack<BSTNode*> my_stack;
    BSTNode* temp = nullptr;
    int size;
    bool left_to_right = true;
    my_queue.push(root);
    while (!my_queue.empty())
    {
        size = my_queue.size();
        for (int i = 0; i < size; i++)
        {
            temp = my_queue.front();
            my_queue.pop();
            if (left_to_right == true) result.push_back(temp->val);
            else my_stack.push(temp);
            if (temp->left) my_queue.push(temp->left);
            if (temp->right) my_queue.push(temp->right);
        }
        if (left_to_right == false)
        {
            while (!my_stack.empty())
            {
                temp = my_stack.top();
                my_stack.pop();
                result.push_back(temp->val);
            }
        }
        left_to_right = !left_to_right;
    }
    return result;
}

