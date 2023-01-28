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

	void InsertBefore(int newValue, int item)
	{
		if (IsEmpty())
		{
			InsertFirst(newValue);
			cout << "the list was empty so we insert it as first node\n";
		}
		else

		{
			if (IsFound(item))
			{
				Node* temp = head;

				while (temp->next->data != item && temp != NULL)
				{
					temp = temp->next;
				}

				Node* nwNode = new Node();
				nwNode->data = newValue;
				nwNode->next = temp->next;
				temp->next = nwNode;
			}
			else
			{
				cout << "the item you want to insert before is not exist\n";
			}
		}

	}

	void append(int lastValue)
	{
		if (IsEmpty())
		{
			InsertFirst(lastValue);
			cout << "the list was empty so we insert it as first node\n";
		}
		else
		{
			Node* temp = head;

			while (temp->next != NULL)
			{
				temp = temp->next;
			}

			Node* nwNode = new Node();
			nwNode->data = lastValue;
			nwNode->next = temp->next;
			temp->next = nwNode;

		}

	}

	void remove(int item)
	{
		if (IsEmpty())

		{
			cout << "The list is Empty, no items to delete\n";
		}
		else
		{
			if (IsFound(item))
			{
				Node* del = head;
				if (head->data == item)
				{
					head = head->next;
					delete del;
				}
				else
				{
					while (del->next->data != item)
					{
						del = del->next;
					}

					Node* deleto = del->next;
					del->next = deleto->next;
					delete deleto;
				}
			}
			else
			{
				cout << "the item you want to delete is not exist\n";
			}
		}
		

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

	/*  INSERT BEFORE */

	cout << "enter the value you want to insert it\n";
	int item0;
	int newVal;
	cin >> newVal;
	cout << "enter the item you want to insert the value before it\n";
	cin >> item0;

	lis1.InsertBefore(newVal, item0);
	lis1.display();


	/* APPEND */
	cout << "enter the value you want to append it\n";
	cin >> item;

	lis1.append(item);
	lis1.display();

	/* DELETE */
	cout << "enter the value you want to delete it\n";
	cin >> item;

	lis1.remove(item);
	lis1.display();



	return 0;
}