#include <iostream>
#include <stack>
#include <queue>
#include <utility>
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

int rangeCount(BTNode* root, int lo, int hi) {
    // STUDENT ANSWER
    int result = 0;
    // A queue for left to right traversal
    queue<BTNode*> my_queue;
    BTNode* temp = nullptr;
    int size;
    my_queue.push(root);
    while (!my_queue.empty())
    {
        size = my_queue.size();
        for (int i = 0; i < size; i++)
        {
            temp = my_queue.front();
            my_queue.pop();
            if (temp->val >= lo && temp->val <= hi) result++;
            if (temp->left) my_queue.push(temp->left);
            if (temp->right) my_queue.push(temp->right);
        }
    }
    return result;
}