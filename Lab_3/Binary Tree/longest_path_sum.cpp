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

void sum_longest_path(BTNode* root, int sum, int len, int& max_len, int& max_sum)
{
    if (!root)
    {
        if (max_len < len)
        {
            max_len = len;
            max_sum = sum;
        }
        else if (max_len == len && max_sum < sum) max_sum = sum;
        return;
    }
    sum_longest_path(root->left, sum + root->val, len + 1, max_len, max_sum);
    sum_longest_path(root->right, sum + root->val, len + 1, max_len, max_sum);
}

int longestPathSum(BTNode* root) {
    if (!root) return 0;
    int max_sum = 0, max_len = 0;
    sum_longest_path(root, 0, 0, max_len, max_sum);
    return max_sum;
}