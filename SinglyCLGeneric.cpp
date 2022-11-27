#include<iostream>
using namespace std;

template<typename T>	// Template Header
struct node
{
	T data;
	struct node *next;
};

template<class T>
class SinglyCL
{
	private:
		node<T> *first;
		node<T> *last;
		int size;
	public:
		SinglyCL();
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
SinglyCL<T> :: SinglyCL()
{
	first = NULL;
	last = NULL;
	size = 0;
}

template<class T>
void SinglyCL<T> :: Display()
{
	node<T> *temp = first;
	if((first == NULL) && (last == NULL))
	{
		return;
	}
	do
	{
		cout<<"|"<<temp->data<<"|->";
		temp = temp->next;
	}while(temp != last->next);
	cout<<"\n";
}

template<class T>
int SinglyCL<T> :: Count()
{
	return size;
}

template<class T>
void SinglyCL<T> :: InsertFirst(T no)
{
	node<T> *newn = new node<T>;		//	Dynamic memory allocation
	newn->next = NULL;
	newn->data = no;
			
	if((first == NULL) && (last == NULL))
	{
		first = newn;
		last = newn;
	}
	else
	{
		newn->next = first;
		first = newn;				
	}
	last->next = first;
	size++;
}
template<class T>
void SinglyCL<T> :: InsertLast(T no)
{
	node<T> *newn = new node<T>;
	newn->next = NULL;
	newn->data = no;
			
	if((first == NULL) && (last == NULL))
	{
		first = newn;
		last = first;
	}
	else
	{
		last->next = newn;
		last = newn;				
	}
	last->next = first;
	size++;
}

template<class T>
void SinglyCL<T> :: InsertAtPos(T no, int ipos)
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
		newn->next = NULL;
		newn->data = no;
				
		node<T> *temp = first;
		for(int i = 1;i < ipos-1;i++)
		{
			temp = temp -> next;
		}
		newn->next = temp->next;
		temp->next = newn;
	}
	last->next = first;
	size++;
}

template<class T>		
void SinglyCL<T> :: DeleteFirst()
{	
	if((first == NULL) && (last == NULL))
	{
		return ;
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
		last->next = first;
	}
	size--;
}

template<class T>
void SinglyCL<T> :: DeleteLast()
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
		node<T> *temp = first;
		while(temp->next != last)
		{
			temp = temp->next;
		}
		delete last;
		last = temp;
		last->next = first;
	}
	size--;
}

template<class T>
void SinglyCL<T> :: DeleteAtPos(int ipos)
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
				
		for(int i = 1; i < ipos - 1;i++)
		{
			temp = temp->next;
		}
				
		node<T> *targated = NULL;
		targated = temp->next;
		temp->next = targated->next;	// temp->next = temp->next->next;
		delete targated;
				
		last->next = first;				
		size--;			
	}
}



int main()
{
	cout<<"------------Singly Circular Linked list----------\n";
	
	SinglyCL <int> obj;
	int ret = 0;
	
	obj.InsertFirst(21);
	obj.InsertFirst(11);
	obj.InsertLast(101);
	obj.InsertLast(151);
	obj.InsertLast(251);
	obj.InsertAtPos(51,3);	
	
	obj.Display();
	ret = obj.Count();

	cout<<"Elements inside linked list are "<<ret<<"\n";	

	obj.DeleteFirst();
	obj.DeleteLast();
	obj.DeleteAtPos(3);
	
	obj.Display();
	ret = obj.Count();
	
	cout<<"Elements inside linked list are "<<ret<<"\n";	
	
	return 0;

}