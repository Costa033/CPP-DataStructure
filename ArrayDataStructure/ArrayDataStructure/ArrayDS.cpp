#include <iostream>
using namespace std;

class Array
{
private:
	int size;
	int length;
	int* items;

public:

	Array(int arrSize)
	{
		size = arrSize;
		length = 0;
		items = new int[arrSize];
	}

	void Fill()
	{
		int itemNO;
		cout << "enter the number of items do you want to enter" << endl;
		cin >> itemNO;

		if (itemNO > size)
		{
			cout << "please enter a number smaller than" << size << endl;
			return;
		}
		else
		{
			for (int i = 0; i < itemNO; i++)
			{
				cout << "enter the value of item number" << i << endl;
				cin >> items[i];
				length++;
			}
		}

	}

	void Display()
	{
		cout << "Display array content"<<endl;

		// here we use length to avoid the display of empty (or RUBBISH) indexes
		for (int i = 0; i < length; i++)
		{
			cout << "the value of the item number  " << i << "  is equal" <<"\t" << items[i] << endl;
		}

	}

	int gSize()
	{
		return size;
	}

	int gLength()
	{
		return length;
	}

	// THIS IS CALLED A LINEAR SEARCH
	void search(int key)
	{
		int index = -1;

		for (int i = 0; i < length;i++)
		{

			if (items[i] == key)
			{
				index = i;
				break;
				//BREAK IS A MUST TO AVOID THE PROGRAM FROM CONTINUE SEARCHING
			}
		}

		if (index == -1)
			{
			cout << "this value not found"<<endl;
			}
		else
			cout<<"the value u search 4 is in the index number\t"<<index<<endl;
	}

	void append(int newItem)
	{
		if (length < size)
		{
			items[length] = newItem;
			length++;
		}
		else
			cout << "the array is full\n";
	}

	//( INSERT AND DELETING ARRAY OPERATIONS IS A HEAVY COST OPERATIONS IN TIME ) --> SO WE USE LINKED LISTS
	// THIS HAPPEN BECAUSE OF SHIFFTING ITEMS (IF ARRAY CONSIST OF 10000 ITEM IT WILL TAKE LOT OF TIME)
	void insert(int indexx, int itemValue)
	{
		if (length < size && indexx >=0 && indexx <size)
		{
			for (int i = length; i > indexx; i--)
			{
				items[i] = items[i - 1];

			}

			items[indexx] = itemValue;
			length++;

		}
		else
			cout << "the array is full or you entered the value in underdefined index\n";

	}

	void remove(int index)
	{
		if (index >= 0 && index < length)
		{
			for (int i = index; i < length; i++)
			{
				items[i] = items[i + 1];

			}
			length--;

		}
		else
			cout << "the index you choose is out of range\n";


	}

	void enlarge(int newSize)
	{
		if (newSize <= size)
		{
			cout << "the new size must be larger than old size\n";
			return;
		}
		else
		{

			size = newSize;
			int* old = items;
			items = new int[newSize];

			for (int i = 0; i < length; i++)
			{
				items[i] = old[i];
			}
			//now we must delete old array
			delete[] old;

		}

	}

	void merge(Array other)
	{
		int newSizo = size + other.gSize();
		//int newLengtho;
		int* old = items;
		items = new int[newSizo];
		int i;
		for ( i = 0; i < length; i++)
		{
			items[i] = old[i];
		}

		delete[] old;

		//int j = i;

		for (int j = 0;j < other.gLength(); j++)
		{
			items[i++] = other.items[j];
			length++;
		}

		size = newSizo;

	}


};

int main()
{
	cout << "this is the Array ADT demo"<<endl;
	int arrSiz;
	cout << "please enter the array size"<<endl;
	cin >> arrSiz;

	Array FisArr(arrSiz);
	FisArr.Fill();

	cout << "the array size is equal " << FisArr.gSize() << endl;
	cout << "the array length is equal " << FisArr.gLength() << endl;

	FisArr.Display();

	/*  search */
	int keyy;
	cout << "enter a value u search 4" << endl;
	cin >> keyy;

	FisArr.search(keyy);
	

	/* append */
	int newiteeem;
	cout << "enter a value you want to append it\n";
	cin >> newiteeem;
	FisArr.append(newiteeem);
	FisArr.Display();

	/* insert */
	int newiteoem , indexo;
	cout << "enter a value you want to insert\n";
	cin >> newiteoem;
	cout << "enter the index you want to insert in it\n";
	cin >> indexo;
	FisArr.insert(indexo , newiteoem);
	FisArr.Display();

	/* delete */
	cout << "enter the index value u want to remove\n";
	int indexRem;
	cin >> indexRem;
	FisArr.remove(indexRem);
	FisArr.Display();

	/* enlarge 

	cout << "enter the new array size\n";
	int newSizze;
	cin >> newSizze;
	FisArr.enlarge(newSizze);
	cout << "the array size is equal " << FisArr.gSize() << endl;
	cout << "the array length is equal " << FisArr.gLength() << endl;
	FisArr.Display();
	*/

	/* Merge */

	Array secondo(5);
	secondo.Fill();

	FisArr.merge(secondo);
	cout << "the array size is equal " << FisArr.gSize() << endl;
	cout << "the array length is equal " << FisArr.gLength() << endl;
	FisArr.Display();


	
	//return 0;
}