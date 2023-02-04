#include <iostream>
using namespace std;


class Node
{
public:
	int data;
	Node* right;
	Node* left;

	Node(int value)
	{
		data = value;
		right = NULL;
		left = NULL;
	}
};


// BST:binary search tree
class BST
{
public:

	Node* root;
	BST()
	{
		root = NULL;
	}


	Node* insert(Node* r, int value)
	{
		if (r == NULL)
		{
			Node* newItem = new Node(value);
			r = newItem;
		}
		else
		{
			if (value < r->data)
				r->left = insert(r->left, value);
			else
				r->right = insert(r->right, value);
		}

		return r;
	}

	void insert(int value)
	{
		root = insert(root, value);
	}

	void PreOrder(Node* r)  //root - left - right
	{
		if (r == NULL)
			return;
		else
		{
			cout << r->data << "\t";
			PreOrder(r->left);
			PreOrder(r->right);
		}
	}

	void InOrder(Node* r)  //left - root - right
	{
		if (r == NULL)
			return;
		else
		{
			InOrder(r->left);
			cout << r->data << "\t";
			InOrder(r->right);
		}
	}

	void PostOrder(Node* r)  //left - right - root 
	{
		if (r == NULL)
			return;
		else
		{
			PostOrder(r->left);
			PostOrder(r->right);
			cout << r->data << "\t";
		}
	}

	void IsFound(Node* r, int item)
	{
		if (r == NULL)
		{
			cout << "Item not found\n";
			return;
		}
		else
		{
			if (r->data == item)
			{
				cout << "the item is found\n";
				return;
			}
			else if (item < r->data)
				IsFound(r->left, item);
			else
				IsFound(r->right, item);
		}
	}

	void IsFound(int item)
	{
		IsFound(root, item);
	}

	Node* search(Node* r, int item)
	{
		if (r == NULL)
		{
			cout << "Item not found\n";
			return NULL;
		}
		else
		{
			if (r->data == item)
			{
				return r;
			}
			else if (item < r->data)
				search(r->left, item);
			else
				search(r->right, item);
		}
	}

	Node* search(int item)
	{
		return search(root, item);
	}

	Node* findMin(Node* r)
	{
		if (r == NULL)
		{
			return NULL;
		}
		else
		{
			if (r->left == NULL)
				return r;
			else
				findMin(r->left);
		}
	}

	Node* findMin()
	{
		return findMin(root);
	}

	Node* findMax(Node* r)
	{
		if (r == NULL)
		{
			return NULL;
		}
		else
		{
			if (r->right == NULL)
				return r;
			else
				findMax(r->right);
		}
	}

	Node* findMax()
	{
		return findMax(root);
	}

	Node* Deleto(Node* r, int key)
	{
		if (r == NULL)  //Empty tree
			return NULL;

		if (key < r->data) //item in the left side of tree
			r->left = Deleto(r->left, key);

		else if (key > r->data)  //item in the right side of tree
			r->right = Deleto(r->right, key);

		else if (key == r->data)
		{
			if (r->left == NULL && r->right == NULL) // Leaf Node
			{
					r = NULL;
			}

			else if (r->left != NULL && r->right == NULL) // one child on the left
			{
					r->data = r->left->data;
					delete r->left;
					r->left = NULL;
			}

			else if (r->left == NULL && r->right != NULL) //one child on the right
			{
					r->data = r->right->data;
					delete r->right;
					r->right = NULL;
			}

			else
			{
					Node* find = findMax(r->left);
					r->data = find->data;
					r->left = Deleto(r->left, find->data);
			}
		}
		
		return r;
		
	}

	void Deleto(int key)
	{
		if (Deleto(root, key) != NULL)
			cout << "Deletion Done\n";
	}
};



int main()
{
	BST btree;
	cout << "enter the number of items you want to store\n";
	int nm;
	cin >> nm;
	int val;
	for (int l = 0;l < nm;l++)
	{
		cout << "enter the number you add\n";
		cin >> val;
		btree.insert(val);
	}
	
	cout << "the tree display by PreOrder way\n";
	btree.PreOrder(btree.root);
	cout << endl;
	cout << "the tree display by PostOrder way\n";
	btree.PostOrder(btree.root);
	cout << endl;
	cout << "the tree display by InOrder way\n";
	btree.InOrder(btree.root);
	cout << endl;

	cout << "enter the item you search for\n";
	int w;
	cin >> w;
	btree.IsFound(w);
	Node* searchRes = btree.search(w);
	if (searchRes == NULL)
		cout << "didn't found" << endl;
	else
		cout << "the data we search for an found it is\t" << searchRes->data << endl;

	Node* min = btree.findMin();
	if (min == 0) //Same meaning of  == NULL
		cout << "no item is exist\n";
	else
		cout << "Minimum is\t" << min->data << endl;

	Node* max = btree.findMax();
	if (max == 0) //Same meaning of  == NULL
		cout << "no item is exist\n";
	else
		cout << "Maximum is\t" << max->data << endl;


	cout << "enter a num you want to delete\n";
	int de;
	cin >> de;
	btree.Deleto(de);


	cout << "the tree display by PreOrder way\n";
	btree.PreOrder(btree.root);
	cout << endl;





	return 0;
}