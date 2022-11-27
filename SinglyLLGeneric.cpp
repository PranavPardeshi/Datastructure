#include<iostream>
using namespace std;

template<typename T>		// Template Header
struct node
{
	T data;
	struct node *next;
};

template<class T>
class SinglyLL
{
	private:
		node<T> *first;
		int size;
	public:		
		SinglyLL();
		void InsertFirst(T);
		void InsertLast(T);
		void InsertAtPos(T,int);
		void DeleteFirst();
		void DeleteLast();
		void DeleteAtPos(int);
		void Display();
		int Count();
};

template<class T>
SinglyLL<T> :: SinglyLL()
{
	first = NULL;
	size = 0;
}

template<class T>
void SinglyLL<T> :: InsertFirst(T no)
{
	node<T> *newn = new node<T>;		// Dynamic memory allocation
			
	newn -> data = no;
	newn -> next = NULL;
			
	if(first == NULL)
	{
		first = newn;
	}
	else
	{
		newn->next = first;
		first = newn;
	}
	size++;
}

template<class T>
void SinglyLL<T> :: InsertAtPos(T no,int ipos)
{
	if((ipos < 1) || (ipos > (size+1)))
	{
		return;
	}
	else if(ipos == 1)
	{
		InsertFirst(no);
	}
	else if(ipos == (size+1))
	{
		InsertLast(no);
	}
	else
	{
		node<T> *newn = new node<T>;
		newn -> data = no;
		newn -> next = NULL;
				
		node<T> *temp = first;
		for(int i = 1; i < ipos-1; i++)
		{
			temp = temp->next;
		}
		newn->next = temp->next;
		temp->next = newn;
				
		size++;
	}
}

template<class T>
void SinglyLL<T> :: InsertLast(T no)
{
	node<T> *newn = new node<T>;
			
	newn -> data = no;
	newn -> next = NULL;
	
	if(first == NULL)
	{
		first = newn;
	}
	else
	{
		node<T> *temp = first;
		while(temp->next != NULL)
		{
			temp = temp->next;
		}
		temp->next = newn;
	}
	size++;		
}

template<class T>
void SinglyLL<T> :: DeleteFirst()
{
	node<T> *temp = first;
	if(first != NULL)
	{
		first = first->next;
		delete temp;
		size--;
	}
}

template<class T>
void SinglyLL<T> :: DeleteLast()
{
	node<T> *temp = first;
			
	if(first == NULL)
	{
		return;
	}
	else if(temp->next == NULL)
	{
		delete first;
		first = NULL;
		size--;
	}
	else
	{
		while(temp->next->next != NULL)
		{
			temp = temp->next;
		}
		delete temp->next;
		temp->next = NULL;
		size--;
	}
}

template<class T>
void SinglyLL<T> :: DeleteAtPos(int ipos)
{
	if((ipos < 1) || (ipos > size))
	{
		return;
	}
	else if(ipos == 1){DeleteFirst();}

	else if(ipos == size){DeleteLast();}
			
	else
	{
		node<T> *temp = first;
		node<T> *targated = NULL;
				
		for(int i = 1;i < ipos-1;i++)
		{
			temp = temp->next;
		}
		targated = temp->next;
		temp->next = targated->next;
		delete targated;
				
		size--;
	}
}

template<class T>
void SinglyLL<T> :: Display()
{
	node<T> *temp = first;
	while(temp != NULL)
	{
		cout<<"|"<<temp->data<<"|->";
		temp = temp->next;
	}
	cout<<"\n";
}

template<class T>
int SinglyLL<T> ::  Count()
{
	return size;
}

////////////////////////////////////////////
int main()
{
	cout<<"-----------Singly Linear Linked List-----------\n";

	SinglyLL <int> sobj;
	int ret = 0;
	sobj.InsertFirst(11);
	sobj.InsertLast(21);
	sobj.InsertLast(51);
	sobj.InsertLast(151);
	sobj.InsertAtPos(101,4);
	

	sobj.Display();
	ret = sobj.Count();
	cout<<"Number of elements inside linkedlist are "<<ret<<"\n";
	
	sobj.DeleteFirst();
	sobj.DeleteLast();

	sobj.Display();

	sobj.DeleteAtPos(3);
	sobj.Display();
	ret = sobj.Count();
	cout<<"Number of elements inside linkedlist are "<<ret<<"\n";
	

	return 0;

}
