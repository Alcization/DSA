#include "main.h"

int MAXSIZE = 0;

class Sukuna
{
	class Node;
private:
	vector<Node* > area_table;
	list<Node* > recent_touch; 
private:
	bool comperation(int index_1, int index_2)
	{
		for (Node* temp : recent_touch)
		{	
			if (temp->ID == area_table[index_2]->ID) return true;
			if (temp->ID == area_table[index_1]->ID) return false;
		}
		return true;
	}
	void reheap_down(int index)
	{
		int left_child = index * 2 + 1;
		int right_child = index * 2 + 2;
		int temp = index;
		if (left_child < (int) area_table.size()) 
		{
			if (area_table[temp]->size() > area_table[left_child]->size() || (area_table[temp]->size() == area_table[left_child]->size() && comperation(temp, left_child) == false)) temp = left_child;		
			if (right_child < (int) area_table.size()) if (area_table[temp]->size() > area_table[right_child]->size() || (area_table[temp]->size() == area_table[right_child]->size() && comperation(temp, right_child) == false)) temp = right_child;
			if (temp != index) 
			{
				swap(area_table[temp], area_table[index]);
				reheap_down(temp);
			}
			else return;
		}
	}
	void reheap_up(int index)
	{
		while (index > 0)
		{
			int parent = (index - 1) / 2;
			if (area_table[index]->size() > area_table[parent]->size()) return;
			if (area_table[index]->size() == area_table[parent]->size())
			{
				for (Node* temp : recent_touch)
				{
					if (temp == area_table[index]) return;
					if (temp == area_table[parent]) break;	
				}
			}
			swap(area_table[index], area_table[parent]);
			index = parent;
		}
	}
	void to_top(Node* node)
	{
		bool found = false;
		list<Node*>::iterator it;
    	it = recent_touch.begin();
		for (Node* temp : recent_touch)
		{
			if (temp == node)
			{	
				found = true;
				break;
			}
			it++;
		}
		if (found == false) recent_touch.push_front(node);
		else recent_touch.splice(recent_touch.begin(), recent_touch, it);
	}
    void removeNode(Node* node)
	{
		list<Node*>::iterator it = std::find(recent_touch.begin(), recent_touch.end(), node);
		recent_touch.erase(it);
	}
public:
	Sukuna(){}
	~Sukuna(){for(int i = 0; i < (int) area_table.size(); i++){delete area_table[i];}}

	void insert_area_table(int result)
	{
		int ID = result % MAXSIZE + 1;
		int index = -1;
		for(int i = 0; i < (int) area_table.size(); i++)
		{
			if (area_table[i]->ID == ID)
			{
				index = i;
				break;
			}
		}
		if (index == -1)
		{
			area_table.push_back(new Node(ID));
			index = area_table.size() - 1;
			area_table[index]->insert(result);
			this->to_top(area_table[index]);
			this->reheap_up(index);
		}
		else 
		{
			area_table[index]->insert(result);
			this->to_top(area_table[index]);
			this->reheap_down(index);
		}	
	}

	void remove_KEITEIKEN(int number)
	{
		if (area_table.size() <= 0) return;
		vector<Node* > areaTableNew(area_table.begin(), area_table.end());
		queue<Node* > list_delete;
		for (int i = 0;  area_table.size() && i < number; i++)
		{
			Node* node_delete = area_table[0];
			swap(area_table[0], area_table[area_table.size() - 1]);
			area_table.pop_back();
			this->reheap_down(0);
			list_delete.push(node_delete);
		}
		area_table = areaTableNew;
		while (list_delete.size())
		{
			Node* node_delete = list_delete.front();
			list_delete.pop();
			node_delete->remove(number);
			int index = 0;
			while (area_table[index] !=  node_delete) index++;
			if (node_delete->size() == 0)
			{
				swap(area_table[index], area_table[area_table.size() - 1]);
				this->removeNode(area_table[area_table.size() - 1]);
				delete area_table[area_table.size() - 1];
				area_table.pop_back();
			}
			this->reheap_down(index);
		}
	}

	void print_pre_order(int index, int number)
	{	
		if (index >= (int) this->area_table.size() || number <= 0) return;
		this->area_table[index]->print(number);
		print_pre_order(index * 2 + 1, number);
		print_pre_order(index * 2 + 2, number);
	}
	void print_LIMITLESS(int number){print_pre_order(0, number);}

private:
	class Node
	{
	private:
		int ID;					
		list<int> head; 	
		friend class Sukuna;
	public:
		Node(int ID) : ID(ID) {}
		int size() const { return head.size(); }
		void insert(int result){head.push_front(result);}
		void remove(int number)
		{
			while(number != 0 && !head.empty())
			{
				cout << head.back() << "-" << ID << "\n";
				head.pop_back();
				number--;
			}
		}
		void print(int number){for(list<int>::iterator it = head.begin(); number > 0 && it != head.end(); ++it, --number) cout << ID << "-" << *it  << "\n";}
	};
};


class Hufftree
{
	class Node;
private:
	Node* root = nullptr;
public:
	~Hufftree(){clear(root);}

	void clear(Node* node)
	{
		if (node)
		{
			clear(node->left);
			clear(node->right);
			delete node;
		}
	}

	void fib()
	{
		int a = 10;
		while (a != 0) a--;
	}

	char encode1(char s, int k)
	{	
		char new_char;
		if (s >= 65 && s <= 90) new_char = ((s - 65) + k) % 26 + 65;
		else if (s >= 97 && s <= 122) new_char = ((s - 97) + k) % 26 + 97;
		fib();
		return new_char;
	}

	struct sort_pred
	{
		bool operator () (const pair<char, int>& left, const pair<char, int>& right)
		{	
			if (left.second == right.second)
			{
				if ((left.first >= 65 && left.first <= 90) && (right.first >= 65 && right.first <= 90))
				{
					if (left.first > right.first) return true;
					else return false;
				}
				if ((left.first >= 97 && left.first <= 122) && (right.first >= 97 && right.first <= 122))
				{
					if (left.first > right.first) return true;
					else return false;
				}
				if (left.first >= 65 && left.first <= 90) return true;
				return false;
			}
			return (left.second > right.second);
		}
	};

	vector<pair<char, int>> string_process(string& name_customer)
	{
		vector<pair<char, int>> previous_freq;
		bool found = false;
		for (int i = 0; i < (int) name_customer.length(); i++)
		{	
			found = false;
			for (int j = 0; j < (int) previous_freq.size(); j++)
			{
				if (name_customer[i] == previous_freq[j].first)
				{	
					found = true;
					previous_freq[j].second++;
					break;
				}
			}
			if (found == false) previous_freq.push_back(make_pair(name_customer[i], 1));
		}
		if (previous_freq.size() < 3) return {};
		string new_s = "";
		for (int i = 0; i < (int) name_customer.length(); i++)
		{
			for (int j = 0; j < (int) previous_freq.size(); j++)
			{
				if (name_customer[i] == previous_freq[j].first)
				{	
					new_s.insert(new_s.end(), encode1(name_customer[i], previous_freq[j].second));
					break;
				}
			}
		}
		name_customer.erase(name_customer.begin(), name_customer.end());
		name_customer = new_s;
		for (int i = 0; i < (int) previous_freq.size(); i++) previous_freq[i].first = encode1(previous_freq[i].first, previous_freq[i].second);
		vector<pair<char, int>> freq;
		for (int i = 0; i < (int) previous_freq.size(); i++)
		{	
			found = false;
			for (int j = 0; j < (int) freq.size(); j++)
			{
				if (freq[j].first == previous_freq[i].first)
				{
					freq[j].second += previous_freq[i].second;
					found = true;
					break;
				}
			}
			if (found == false) freq.push_back(previous_freq[i]);
		}
		stable_sort(freq.begin(), freq.end(), sort_pred());
		return freq;
	}

	int height(Node* node) 
	{
		if (node == nullptr) return 0;
		return max(height(node->left), height(node->right)) + 1;
	}

	int get_balance(Node* node)
	{
		if (node == nullptr) return 0;
		return height(node->left) - height(node->right);
	}

	Node* rotate_right(Node* root) 
	{
		Node* temp = root->left;
		root->left = temp->right;
		temp->right = root;
		return temp;
	}
	
	Node* rotate_left(Node* root) 
	{
		Node* temp = root->right;
		root->right = temp->left;
		temp->left = root;
		return temp;
	}

	Node* balance_node(Node* node, int& count) 
	{
		if (count == 3) return node;
		int balance = get_balance(node);
		if (balance > 1)
		{
			if (get_balance(node->left) >= 0) 
			{   
				node = rotate_right(node);
				count++;
			}
			else
			{
				node->left = rotate_left(node->left);	
				node = rotate_right(node);
				count++;
			}
		}
		else if (balance < -1)
		{
			if (get_balance(node->right) <= 0) 
			{
				node = rotate_left(node);
				count++;
			}
			else
			{
				node->right = rotate_right(node->right);
				node = rotate_left(node);
				count++;
			}
		}
		else return node;
		return node;
	}

	Node* balance_tree(Node* node, int count = 0)
	{
		if (node == nullptr || count == 1) return node; 
		node = balance_node(node, count);
		node->left = balance_tree(node->left, count);
		node->right = balance_tree(node->right, count);
		return node;
	}

	Node* plant_huff_tree(vector<pair<char, int>> freq)
	{
		vector<Node*> build;
		for (int i = 0; i < (int) freq.size(); i++)
		{
			Node* node = new Node(freq[i].second, freq[i].first);
			build.push_back(node);
		}
		while(build.size() > 1)
		{
			Node* left = build.back();
			build.pop_back();
			Node* right = build.back();
			build.pop_back();
			Node* newNode = new Node(0, '\0', left, right);
			newNode->weight = left->weight + right->weight;
			int count = 0;
			for (int k = 0; k < 3; k++) newNode = balance_tree(newNode, count);
			vector<Node*>::iterator it = build.begin();
			bool found = false;
			for (int i = 0; i < (int) build.size(); i++, it++) 
			{
				if (newNode->weight >= build[i]->weight)
				{
					build.insert(it, newNode);
					found = true;
					break;
				}
			}
			if (!found) build.push_back(newNode);
		}		
		return build[0];
	}
	int bin_to_dec(string n)
	{
		string number = n;
		int dec_value = 0;
		int base = 1;
		int len = number.size();
		for (int i = len - 1; i >= 0; i--) {
			if (number[i] == '1')
				dec_value += base;
			base = base * 2;
		}
		fib();
		return dec_value;
	}

	void encoding_huffman_tree(vector<string>& encoding, Node* node, string s = "")
	{
		if (node->left == nullptr && node->right == nullptr)
		{   
			int index = node->c - '0' + 48;
			encoding[index] = s;
			return;
		} 
		if (node->left != nullptr)
		{   
			string left = s;
			left += "0";
			encoding_huffman_tree(encoding, node->left, left);
		}
		if (node->right != nullptr) 
		{   
			string right = s;
			right += "1";
			encoding_huffman_tree(encoding, node->right, right);
		}
	}
	int encoding_huffman(Node * root,string name_caesar)
	{
		if (root->left == nullptr && root->right == nullptr) return 0;
		vector<string> encoding(256, ""); 
		encoding_huffman_tree(encoding, root);
		string binary;
		while (binary.size() < 10 && !name_caesar.empty()) 
		{   
			char str = name_caesar.back();
			name_caesar.pop_back();
			int index = str - '0' + 48;
			binary = encoding[index] + binary;
		}
		if (binary.size() > 10)
		{
			int i = binary.size() - 10;
			binary = binary.substr(i, 10);
		}
		reverse(binary.begin(), binary.end());
		int result = 0;
		result = bin_to_dec(binary);
		fib();
		return result;
	}


	int encode(string name_customer)
	{
		vector<pair<char, int>> freq  = this->string_process(name_customer);
		if (freq.size() == 0) return -1;
		this->clear(root);
		root = this->plant_huff_tree(freq);
		if (root->left == nullptr && root->right == nullptr) return 0; 
		int result = this->encoding_huffman(root, name_customer);
		fib();
		return result;
	}

	void print_rec(Node* node)
	{
		if (node == nullptr) return;
		print_rec(node->left);
		if (node->c == '\0') cout << node->weight << "\n";
		else cout << node->c << "\n";
		print_rec(node->right);
		fib();
	}
	void print_HAND(){print_rec(root);}

private:
	class Node
	{
	public:
		int weight;
		char c;
		Node* left;
		Node* right;
		friend class Hufftree;
	public:
		Node(int weight, char c = '\0',Node* left = nullptr, Node* right = nullptr ):  weight(weight), c(c), left(left), right(right) {}
	};
};

class Gojo
{
	class BST_Tree;
private:
	vector<BST_Tree> area_table;
public:
	Gojo():area_table(MAXSIZE + 1){}
	void insert_area_table(int result)
	{
		int ID = result % MAXSIZE + 1;
		area_table[ID].insert(result); 
	}
	void remove_KOKUSEN()
	{
		int i = 1;
		while (i < MAXSIZE + 1) 
		{
			area_table[i].remove();
			i++;
		}
	}

	void print_LIMITLESS(int number)
	{
		if (number > MAXSIZE || number <= 0) return;
		area_table[number].print();
	}
private:
	class BST_Tree
	{
		class Node;
	private:
		Node* root;	
		queue<int> time_queue; 
	public:
		BST_Tree():root(nullptr){}
		~BST_Tree()
		{
			while(!time_queue.empty())
			{
				int temp = time_queue.front();		
				time_queue.pop(); 						
				root = remove_rec(root, temp);
			}
		}
		int size(){return time_queue.size();}
		Node* insert_rec(Node* node, int result)
		{
			if (node == nullptr) 
			{
				time_queue.push(result);
				return new Node(result);
			} 
    		if (node->result <= result) node->right = insert_rec(node->right, result);
    		else node->left = insert_rec(node->left, result);
			return node;
		}
		void insert(int result){root = insert_rec(root, result);}
		Node* remove_rec(Node* node,int result)
		{
    		if (node == nullptr) return nullptr;
    		if (node->result < result) node->right = remove_rec(node->right, result);	
    		else if (node->result > result) node->left = remove_rec(node->left, result);
   		 	else if (node->result == result)
    		{
        		Node* node_Delete = node;
        		if (node->left == nullptr && node->right == nullptr) node = nullptr;		
        		else if (node->right == nullptr) node = node->left;
				else if (node->left == nullptr) node = node->right;
        		else 
        		{
           			Node* temp = node->right;
            		while(temp->left != nullptr) temp = temp->left;
            		swap(node->result, temp->result);
            		node->right = remove_rec(node->right, result);
            		return node;
        		}
        		delete node_Delete;
    		}
    		return node;
		}
		int count_node(Node* node) 
		{
			if (node == nullptr) return 0;
			int left = count_node(node->left);
			int right = count_node(node->right);
			return left + right + 1;
		}
		unsigned long long permutation(int x, int n)
		{
			vector<vector<unsigned long long>> calculator(n+1, vector<unsigned long long>(x+1, 0));
			for (unsigned long long i = 0; i <= (unsigned) n; i++)
			{
				for (unsigned long long j = 0; j <= (unsigned) x && j <= i; j++)
				{
					if (j == 0 || j == i) calculator[i][j] = 1;
					else calculator[i][j] = (calculator[i-1][j-1] % MAXSIZE + calculator[i-1][j] % MAXSIZE);
				}
			}
			return calculator[n][x] % MAXSIZE;
		}
		unsigned long long deep_calculator(Node* node)
		{
			if (node == nullptr) return 1;
			int left_size = count_node(node->left);
			int right_size = count_node(node->right);
			unsigned long long left = deep_calculator(node->left);
			unsigned long long right = deep_calculator(node->right);
			return (permutation(left_size, left_size + right_size) * left * right) % MAXSIZE ;
		}
		void remove()
		{
			if (time_queue.empty()) return;
			unsigned long long number = deep_calculator(root) % MAXSIZE;
			while (number != 0 && !time_queue.empty())
			{
				int temp = time_queue.front();		
				time_queue.pop(); 					
				root = remove_rec(root ,temp);
				number--;
			}
		}
		void print_rec(Node* node)
		{
			if (node != nullptr)
			{
				print_rec(node->left);
				cout << node->result << "\n";
				print_rec(node->right);
			}
		}
		void print(){print_rec(root);}
	private:
		class Node
		{
		private:
			int result;
			Node* left;
			Node* right;
			friend class BST_Tree;
		public:
			Node(int result) : result(result), left(nullptr), right(nullptr) {}
		};
	};

};

class Main_operation;
class Gojo;
class Sukuna;
class Hufftree;

class Main_operation
{
private:
	Hufftree new_customer;
	Gojo hash;
	Sukuna heap;
public:
	void LAPSE(string name_customer)
	{	
		int result = new_customer.encode(name_customer);
		if (result == -1) return;
		if (result % 2 == 1) hash.insert_area_table(result);
		else heap.insert_area_table(result);
	}	
	void KOKUSEN(){hash.remove_KOKUSEN();}
	void LIMITLESS(int number){hash.print_LIMITLESS(number);}
	void KEITEIKEN(int number){heap.remove_KEITEIKEN(number);}
	void CLEAVE(int number){heap.print_LIMITLESS(number);}
	void HAND(){new_customer.print_HAND();}
};

void simulate(string filename)
{
	ifstream command(filename);
	string str, name_customer;
	int number;
	command >> str; command >> MAXSIZE; 
	Main_operation* PC = new Main_operation();
	while (command >> str)
	{
		if (str == "LAPSE") 
		{
			command >> name_customer;
			PC->LAPSE(name_customer);
			continue;
		}
		if (str == "KOKUSEN") 
		{
			PC->KOKUSEN();
			continue;
		}
		if (str == "KEITEIKEN")
		{
			command >> number;
			PC->KEITEIKEN(number);
			continue;
		}
		if (str == "HAND") 
		{
			PC->HAND();
			continue;
		}		
		if (str == "LIMITLESS") 
		{
			command >> number;
			PC->LIMITLESS(number);
			continue;
		}		
		if (str == "CLEAVE") 
		{
			command >> number;
			PC->CLEAVE(number);
			continue;
		}				
	}
	delete PC;
}

