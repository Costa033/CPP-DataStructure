#include <iostream>
using namespace std;
#include <string>

class Node
{
public:

	int data;
	Node* next;

};

class stack
{
	Node* top;

public:

	stack()
	{
		top = NULL;
	}

	bool IsEmpty()
	{
		return(top == NULL);
	}

	bool IsFull()
	{
		Node* full = new Node();
		if (full == NULL)
			return true;
		else
			return false;
	}

	bool IfContain(int item)
	{
		Node* temp = top;
		bool stat = false;

		while (temp != NULL)
		{
			if (temp->data == item)
				stat = true;

			temp = temp->next;
		}
		return stat;

	}

	void push(int item)
	{
		Node* NewNode = new Node();
		NewNode->data = item;

		if (IsEmpty())
		{
			NewNode->next = NULL;
			top = NewNode;
		}
		else
		{
			
			NewNode->next = top;
			top = NewNode;
		}

	}

	int pop()
	{

		Node* temp = top;
		top = top->next;
		return temp->data;
		delete temp;
	}

	int peek()
	{
		return top->data;
	}

	void display()
	{
		Node* temp = top;

		cout << "the stack items is\n";

		while (temp != NULL)
		{
			cout << temp->data << endl;
			temp = temp->next;
		}
		cout << "the stack is fully displayed\n";

	}

	int count()
	{
		Node* count = top;
		int counter = 0;
		while (count != NULL)
		{
			counter++;
			count = count->next;
		}
		return counter;
	}


};



int main()
{
	stack ss;
	int ite;

	/*cout << "push the first value";
	cin >> ite;
	ss.push(ite);*/

	for(int i=0;i<5;i++)
	{
		cout << "please enter items to push\n";
		cin >> ite;
		ss.push(ite);
	}

	ss.display();
	
	cout << "the number of items in the stack is equal " << ss.count() << endl;
	//cout << "please  press to pop the last num\n";
	int x = ss.pop();
	cout << "the number we bob is  "<<x << endl;
	ss.display();

	cout << "the number of items in the stack is equal " << ss.count()<< endl;

	/* SEARCH */

	cout << "enter a num u want to search for\n";
	int sss;
	cin >> sss;
	if (ss.IfContain(sss))
		cout << "the number is found\n";
	else
		cout << "number not found\n";

	/* IS FULL */

	if (ss.IsFull())
		cout << "the heap is full\n";
	else
		cout << "the heap isn't full\n";

	return 0;
}