// Exercise 2: Implement insert in AVL for these cases: balanced, L-L, R-L

#include <iostream>
#include <math.h>
#include <queue>
 
using namespace std;
 
enum BalanceValue
{
	LH = -1,
	EH = 0,
	RH = 1
};
 
void printNSpace(int n)
{
	for (int i = 0; i < n - 1; i++)
		cout << " ";
}
 
void printInteger(int &n)
{
	cout << n << " ";
}
 
template<class T>
class AVLTree
{
public:
    class Node;
private:
    Node *root;
protected:













    int getHeightRec(Node *node)
	{
		if (node == nullptr)
			return 0;
		int lh = this->getHeightRec(node->pLeft);
		int rh = this->getHeightRec(node->pRight);
		return (lh > rh ? lh : rh) + 1;
	}
public:
    AVLTree() : root(nullptr) {}
    ~AVLTree(){}
	int getHeight()
	{
		return this->getHeightRec(this->root);
	}
	void printTreeStructure()
	{
		int height = this->getHeight();
		if (this->root == nullptr)
		{
			cout << "nullptr\n";
			return;
		}
		queue<Node *> q;
		q.push(root);
		Node *temp;
		int count = 0;
		int maxNode = 1;
		int level = 0;
		int space = pow(2, height);
		printNSpace(space / 2);
		while (!q.empty())
		{
			temp = q.front();
			q.pop();
			if (temp == nullptr)
			{
				cout << " ";
				q.push(nullptr);
				q.push(nullptr);
			}
			else
			{
				cout << temp->data;
				q.push(temp->pLeft);
				q.push(temp->pRight);
			}
			printNSpace(space);
			count++;
			if (count == maxNode)
			{
				cout << endl;
				count = 0;
				maxNode *= 2;
				level++;
				space /= 2;
				printNSpace(space / 2);
			}
			if (level == height)
				return;
		}
	}
 












// STUDENT_ANSWER BEGIN
//Helping functions
Node* rotateRight(Node* root) 
{
    Node* temp = root->pLeft;
    root->pLeft = temp->pRight;
    temp->pRight = root;
    return temp;
}
 
Node* rotateLeft(Node* root) 
{
    Node* temp = root->pRight;
    root->pRight = temp->pLeft;
    temp->pLeft = root;
    return temp;
}

Node* leftBalance(Node* & root, bool & taller)
{
    Node* leftTree = root->pLeft;
    if(leftTree->balance == LH)
    {
        root = rotateRight(root);
        root->pRight->balance = EH;
        leftTree->balance = EH;
        taller = false;
    }
    else
    {
        Node* rightTree = leftTree->pRight;
        if(rightTree->balance == LH)
        {
            root->balance = RH;
            leftTree->balance = EH;
        }
        else if(rightTree->balance == EH)
        {
            leftTree->balance = EH;
            root->balance = EH;
        }
        else
        {
            root->balance = EH;
            leftTree->balance = LH;
        }
        rightTree->balance = EH;
        root->pLeft = rotateLeft(leftTree);
        root = rotateRight(root);
        taller = false;
    }
    return root;
}

Node* rightBalance(Node* & root, bool & taller)
{
    Node* rightTree = root->pRight;
    if(rightTree->balance == RH)
    {
        root = rotateLeft(root);
        root->pLeft->balance = EH;
        rightTree->balance = EH;
        taller = false;
    }
    else
    {
        Node* leftTree = rightTree->pLeft;
        if(leftTree->balance == RH)
        {
            root->balance = LH;
            rightTree->balance = EH;
        }
        else if(leftTree->balance == EH)
        {   
            root->balance = EH;
            rightTree->balance = EH;
        }
        else
        {
            root->balance = EH;
            rightTree->balance = RH;
        }
        leftTree->balance = EH;
        root->pRight = rotateRight(rightTree);
        root = rotateLeft(root);
        taller = false;
    }
    return root;
}

Node* insert_rec(Node* & root, Node* new_ptr, bool& taller)
{
    if(root == nullptr)
    {
        root = new_ptr;
        taller = true;
        return root;
    }
    if(new_ptr->data < root->data)
    {
        root->pLeft = insert_rec(root->pLeft, new_ptr, taller);
        if(taller)
        {
            if(root->balance == LH)
            { // case 1: LH
                root = leftBalance(root, taller);
            }
            else if(root->balance == EH)
            { // case 2 : EH
                root->balance = LH;    
            }
            else
            { // case 3: RH
                root->balance = EH;
                taller = false;
            }
        }
    }
    else
    {
        root->pRight = insert_rec(root->pRight, new_ptr, taller);
        if(taller)
        {
            if(root->balance == RH) 
            {
                root = rightBalance(root, taller);
            }
            else if(root->balance == EH)
            {
                root->balance = RH;
            }
            else
            {
                root->balance = EH;
                taller = false;
            }
        }
    }
    return root;
}

void insert(const T &value)
{
    //TODO
    Node* pointer = new Node(value);
    bool taller = false;
    insert_rec(this->root, pointer, taller);
}
// STUDENT_ANSWER END


class Node
    {
    private:
        T data;
        Node *pLeft, *pRight;
		BalanceValue balance;
        friend class AVLTree<T>;
 
    public:
        Node(T value) : data(value), pLeft(nullptr), pRight(nullptr), balance(EH) {}
        ~Node() {}
    };
};
int main() {
	// TEST 1
	{
		AVLTree<int> avl;
		for (int i = 0; i >= -10; i--){
		    avl.insert(i);
		}
		avl.printTreeStructure();
		// EXPECTED
		//       -3
		//   -7       -1
		//  -9   -5   -2   0
		// -10 -8 -6 -4
	}
	// TEST 2
	{
		AVLTree<int> avlTree;
		avlTree.insert(5);
		avlTree.insert(7);
		avlTree.insert(6);
		avlTree.printTreeStructure();
		// EXPECTED
		//  6
		// 5 7
	}
    return 0;
}