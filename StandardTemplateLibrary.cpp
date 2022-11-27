#include<iostream>
using namespace std;

template<typename T>		
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

/////////////////////////////////////////////////////////////////////////////////////////

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
/////////////////////////////////////////////////////////////////////////////////////////

template<typename T>
struct node
{
    T data;
    struct node *next;
    struct node *prev;
};


template<class T>
class DoublyLL
{
    private:
        int size;
        node<T> *first;
        node<T> *last;

    public:
        DoublyLL();
        void InsertFirst(T);
        void InsertLast(T);
        void InsertAtPos(T,int);
        void DeleteFirst();
        void DeleteLast();
        void DeleteAtPos(int);
        int Count();
        void Display();
};

template<class T>
DoublyLL<T> :: DoublyLL()
{
    size = 0;
    first = NULL;
    last = NULL;
}

template<class T>
void DoublyLL<T> :: InsertFirst(T no)
{
    node<T> *newn = new node<T>;
    newn->data = no;
    newn->next = NULL;
    newn->prev = NULL;

    if((first == NULL) && (last == NULL))
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
    first->prev = NULL;
    last->next = NULL;
    size++;
}

template<class T>
void DoublyLL<T> :: InsertLast(T no)
{
    node<T> *newn = new node<T>;
    newn->data = no;
    newn->next = NULL;
    newn->prev = NULL;
            
    if((first == NULL) && (last == NULL))
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
    last->next = NULL;
    first->prev = NULL; 
    size++;       
}

template<class T>
void DoublyLL<T> :: InsertAtPos(T no, int ipos)
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
        for(int i=1; i < ipos-1;i++)
        {
            temp = temp->next;
        }
        newn->next = temp->next;
        temp->next->prev = newn;
        temp->next = newn;
        newn->prev = temp;
    }
    first->prev = NULL;
    last->next = NULL;
    size++; 
}

template<class T>
void DoublyLL<T> :: DeleteFirst()
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
        first = first->next;
        delete temp;
    }
    first->prev = NULL;
    last->next = NULL;
    size--;
}

template<class T>
void DoublyLL<T> :: DeleteLast()
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
        node<T> *temp = last;
        last = last->prev;
        delete temp;
    }
    last->next = NULL;
    first->prev = NULL;
    size--;    
}

template<class T>
void DoublyLL<T> :: DeleteAtPos(int ipos)
{
    if((ipos < 1) || (ipos > size+1))
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
        for(int i = 1; i < ipos -1; i++)
        {
            temp = temp->next;
        }
        node<T> *targated = temp->next;
        temp->next = targated->next;
        targated->next->prev = temp;
        delete targated;

        first->prev = NULL;
        last->next = NULL;

        size--;
    }
}

template<class T>
void DoublyLL<T> :: Display()
{
    node<T> *temp = first;
    while(temp!=NULL)
    {
        cout<<"|"<<temp->data<<"|->";
		temp = temp->next;
    }
    cout<<"\n";
}

template<class T>
int DoublyLL<T> :: Count()
{
    return size;
}


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

