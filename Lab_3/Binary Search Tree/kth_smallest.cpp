#include <iostream>
#include <vector>
#include <stack>
#include <queue>
#include <algorithm>
#include <climits>
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

int kthSmallest(BSTNode* root, int k) {
    // STUDENT ANSWER
    vector<int> result;
    if (root == nullptr) return 0;
    if (root->left == nullptr && root->right == nullptr) return root->val;
    // A queue for left to right traversal
    queue<BSTNode*> my_queue;
    BSTNode* temp = nullptr;
    int size;
    my_queue.push(root);
    while (!my_queue.empty())
    {
        size = my_queue.size();
        for (int i = 0; i < size; i++)
        {
            temp = my_queue.front();
            my_queue.pop();
            result.push_back(temp->val);
            if (temp->left) my_queue.push(temp->left);
            if (temp->right) my_queue.push(temp->right);
        }
    }
    sort(result.begin(), result.end());
    return result[k-1]; 
}

