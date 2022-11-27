#include<iostream>
using namespace std;

template<typename T>
struct node 
{
	T data;
	struct node *next;
	struct node *prev;
};

template<class T>
class DoublyCL
{
	private:
		int size;
		node<T> *first;
		node<T> *last;
		
	public:
		DoublyCL();
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
DoublyCL<T> :: DoublyCL()
{
    size = 0;
    first = NULL;
    last = NULL;
}


template<class T>
void DoublyCL<T> :: InsertFirst(T no)
{
	node<T> *newn = new node<T>;
			
	newn->data = no;
	newn->prev = NULL;
	newn->next = NULL;
			
	if((first == NULL) && (last==NULL))
	{
		first = newn;
		last = newn;
	}
	else
	{
		newn->next = first;
		first->prev = newn;
		first = newn;
	}
	last->next = first;
	first->prev = last;
	size++;
}

template<class T>
void DoublyCL<T> :: InsertLast(T no)
{
	node<T> *newn = new node<T>;
			
	newn->data = no;
	newn->next = NULL;
	newn->prev = NULL;
			
	if((first == NULL)&&(last == NULL))
	{
		first = newn;
		last = newn;
	}
	else
	{
		last->next = newn;
		newn->prev = last;
		last = newn;
	}
	last->next = first;
	first->prev = last;
	size++;
}

template<class T>
void DoublyCL<T> :: InsertAtPos(T no,int ipos)
{
	if((ipos < 1) || (ipos > size+1))
	{
		return;
	}
	else if(ipos == 1)
	{
		InsertFirst(no);
	}
	else if(ipos == size+1)
	{
		InsertLast(no);
	}
	else
	{
		node<T> *newn = new node<T>;
		newn->data = no;
		newn->next = NULL;
		newn->prev = NULL;
				
		node<T> *temp = first;
		for(int i = 1; i < ipos-1 ; i++)
		{
			temp = temp->next;
		}
		newn->next = temp->next;
		temp->next->prev = newn;
		temp->next = newn;
		newn->prev = temp;
				
		size++;
	}
}

template<class T>
void DoublyCL<T> :: DeleteFirst()
{
	if((first == NULL) && (last == NULL))
	{
		return;
	}
	else if(first == last)
	{
		delete first;
		first = NULL;
		last = NULL;
	}
	else
	{	
		first = first->next;
		delete last->next;
		first->prev = last;
		last->next = first;
	}
	size--;			
}

template<class T>
void DoublyCL<T> ::DeleteLast()
{
	if((first == NULL) && (last == NULL))
	{
		return;
	}
	else if(first == last)
	{
		delete first;
		first = NULL;
		last = NULL;
	}
	else
	{
		last = last->prev;
		delete last->next;
		first->prev = last;
		last->next = first;
	}
	size--;
}

template<class T>
void DoublyCL<T> :: DeleteAtPos(int ipos)
{
	if((ipos < 1) || (ipos > size))
	{
		return;
	}
	else if(ipos == 1)
	{
		DeleteFirst();
	}
	else if(ipos == size)
	{
		DeleteLast();
	}
	else
	{
		node<T> *temp = first;
		
		for(int i = 1; i < ipos-1; i++)
		{
			temp = temp->next;
		}
		temp->next = temp->next->next;
		delete temp->next->prev;
		temp->next->prev = temp;
				
		size--;
	}
				
}


template<class T>
void DoublyCL<T> :: Display()
{
	node<T> *temp = first;
			
	for(int i = 1; i <= size; i++)
	{
		cout<<"|"<<temp->data<<"|->";
		temp = temp->next;
	}
	cout<<"\n";
}

template<class T>
int DoublyCL<T> :: Count()
{
	return size;
}



int main()
{
	cout<<"----------Doubly Circular linked list----------\n";
	
	DoublyCL <int> obj;
	int iret = 0;
	
	
	obj.InsertLast(101);
	obj.InsertFirst(21);
	obj.InsertFirst(11);
	obj.InsertAtPos(51,3);
	obj.InsertAtPos(111,5);
	
	obj.Display();
	iret = obj.Count();
	
	cout<<"Elements in linkedlist are "<<iret<<"\n";
		
	obj.DeleteLast();
	obj.DeleteFirst();
	obj.DeleteAtPos(3);
	
	obj.Display();
	iret = obj.Count();
	cout<<"Elements in linkedlist are "<<iret<<"\n";
	
	return 0;
}