#include <iostream>
using namespace std;

class Node
{
public:
	int data;
	Node* next;

	Node()
	{
		data = 0;
		next = NULL;
	}
};

class Queue
{
public:
	Node* front;
	Node* rear;

	Queue()
	{
		front = rear = NULL;
	}

	bool IsEmpty()
	{
		return(front == NULL && rear == NULL);
	}

	bool IsFound(int item)
	{
		Node* temp = front;
		bool stat = false;

		while (temp != NULL)
		{
			if (temp->data == item)
			{
				stat = true;
				break;
			}

			temp = temp->next;
		}
		return stat;
	}

	int count()
	{
		int counter = 0;
		Node* temp = front;

		while (temp != NULL)
		{
			counter++;
			temp = temp->next;
		}
		return counter;
	}

	void enqueue(int item)
	{
		Node* newItem = new Node();
		newItem->data = item;

		if (IsEmpty())
		{
			rear = newItem;
			front = newItem;
		}
		else
		{
			rear->next = newItem;
			rear = newItem;
		}

	}

	void dequeue()
	{
		if (IsEmpty())
		{
			cout << "there are no items to dequeue\n";
		}
		else if (count() == 1)
		{
			Node* delptr = front;
			front = rear = NULL;
			delete delptr;
		}
		else
		{
			Node* delptr = front;
			front = front->next;
			delete delptr;
		}
	}

	int getFront()
	{
		return front->data;
	}

	int getRear()
	{
		return rear->data;
	}

	void display()
	{
		if (IsEmpty())
			cout << "the queue is empty\n";
		else

		{
			Node* temp = front;
			while (temp != NULL)
			{
				cout << temp->data << " ";
				temp = temp->next;
			}
			cout << endl;
		}
	}

	void clear()
	{
		while(IsEmpty()!=true)
		{
			dequeue();
		}

	}

};

int main()
{
	int v;
	Queue qu;

	for (int i = 0;i < 6;i++)
	{
		cout << "enter a num to enqueue\n";
		cin >> v;
		qu.enqueue(v);
	}

	qu.display();

	cout << "enter the number of items you want to dequeue\n";
	int n;
	cin >> n;
	if(n<=qu.count())

	{
		for (int i = 0;i < n;i++)
		{
			qu.dequeue();
			qu.display();
		}
	}
	else
	{
		cout << "the number is bigger than the number of items in queue\n";
	}
	cout << "now the queue is \n";

	qu.display();


	cout << "enter the number you want to search for\n";
	int serr;
	cin >> serr;

	if (qu.IsFound(serr))
		cout << "the number is found\n";
	else
		cout << "the number is not found\n";


	cout << "the number of items is " << qu.count() << endl;

	cout << "if you want to clear the queue .. enter -1\n";
	cin >> serr;
	if (serr == -1)
	{
		qu.clear();
	}

	qu.display();

	return 0;
}