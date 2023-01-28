#include <iostream>
using namespace std;
#include <string>

class Node
{
public:

	int data;
	Node* next;

};

class LinkedList
{
public:

	Node* head;

	// first we will creat and check the list is empty

	LinkedList()
	{
		head = NULL;
	}

	bool IsEmpty()
	{
		/*if (head == NULL)
			return true;
		else
			return false;*/

		return(head == NULL);

	}

	// here we will start to fill the list (Insertion)

	void InsertFirst(int newValue)
	{
		Node* Newnode = new Node();
		Newnode->data = newValue;

		if (IsEmpty())
		{
			Newnode->next = NULL;
			//head = Newnode;
		}
		else
		{
			Newnode->next = head;
			//head = Newnode;
		}
		head = Newnode;
	}

	// here we will Display the List (Traversing Operations)

	void display()
	{
		Node* temp = head;
		//int i = 1;
		while (temp != NULL)
		{
			cout << temp->data  << "\t";
			//i++;
			temp = temp->next;
		}
			
		cout << "\n the list is fully displayed\n";
	}

	int count()
	{
		Node* temp = head;
		int counter = 0;
		while (temp != NULL)
		{
			counter++;
			temp = temp->next;
		}
		
		return counter;
	}

	bool IsFound(int key)
	{
		bool found = false;

		Node* temp = head;
		while (temp != NULL)
		{
			if (temp->data == key)
			{
				found = true;
			}

			temp = temp->next;
		}
		return found;
	}

};


int main()
{
	LinkedList lis1;
	//LinkedList();

	if (lis1.IsEmpty())
		cout << "the list is EMPTY\n";
	else
		cout << "the list Contains\t"<< lis1.count()<<"\titems"<<endl;

	/* FILL */
	int item;
	for(int c=1; c<=3;c++)
	{
		cout << "enter an item to insert in the list\n";
		cin >> item;
		lis1.InsertFirst(item);
		lis1.display();
	}
	
	cout << "the list Contains\t" << lis1.count() << "\titems" << endl;

	/* SEARCH */
	cout << "enter an item to search in the list\n";
	cin >> item;
	if (lis1.IsFound(item))
		cout << "the item is found\n";
	else
		cout << "the item is not found\n";



	return 0;
}