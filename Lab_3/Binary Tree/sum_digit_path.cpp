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

int stack_to_int(stack<int> st)
{
    vector<int> q;
    while(!st.empty())
    {
        q.insert(q.begin(),st.top());
        st.pop();
    }
    int ans = 0;
    while(!q.empty())
    {
        int tmp = q[0];
        q.erase(q.begin());
        ans = ((ans*10) + tmp) % 27022001 ;
    }
    return ans;
}

int sumDigitPathRec(BTNode* root, stack<int>& st)
{
    if(root == nullptr) return 0;
    if(root->left == nullptr && root->right == nullptr)
    {
        st.push(root->val);
        int ans = stack_to_int(st);
        st.pop();
        return ans;
    }
    st.push(root->val);
    int ans = (sumDigitPathRec(root->left, st) + sumDigitPathRec(root->right, st)) % 27022001;
    st.pop();
    return ans;
}

int sumDigitPath(BTNode* root) 
{
    stack<int> st;
    return sumDigitPathRec(root, st);
}