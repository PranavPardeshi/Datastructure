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



int main()
{
    cout<<"----------Doubly Linear linked list----------\n";

    DoublyLL <int>obj;
    

    int iRet = 0;
    obj.InsertFirst(21);
    obj.InsertFirst(11);
    obj.InsertLast(101);
    obj.InsertAtPos(51,3);
    obj.Display();
    
    //ptr->DeleteFirst();
    //ptr->DeleteLast();  
    obj.DeleteAtPos(3);
    obj.Display();

    iRet = obj.Count();
    cout<<"Elements inside linkedlist are : "<<iRet;

    return 0;
}